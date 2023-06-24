#include <symbo/symbo.hpp>
#include <symbo/parser.hpp>

namespace symbo {
	Parser::Parser(std::string string) : m_string(std::move(string)), m_lexer(m_string) {}

	std::string Parser::str() const { return m_string; }

	Lexer Parser::lexer() const { return m_lexer; }

	std::shared_ptr<Component> Parser::tree() const { return m_tree; }

	void Parser::advance(int64_t dist) {
		if (m_pos >= m_lexer.tokens().size()) {
			throwError("Parsing could not be completed successfully");
		}
		m_pos += dist;
	}

	void Parser::clear() {
		m_string = "";
		m_lexer.clear();
		m_pos  = 0;
		m_tree = nullptr;
	}

	void Parser::reset() {
		m_lexer.reset();
		m_pos  = 0;
		m_tree = nullptr;
	}

	void Parser::parse() {
		m_lexer.tokenize();
		m_lexer.postProcess();

		if (finished()) return;

		// Eat tokens one-by-one, interpreting their meaning appropriately
		// For now, assume we are parsing a single expression
		m_tree = eatExpression();

		// Ensure the full list of tokens has been consumed
		if (!finished()) { throwError("Could not parse expression"); }
	}

	bool Parser::eatPlusMinus() {
		bool sign = false;
		bool cont = true;
		while (cont) { // Consume multiple +/- signs if possible
			if (m_lexer.tokens()[m_pos].type == Type::TOKEN_SUB) {
				sign = !sign;
				advance();
			} else if (m_lexer.tokens()[m_pos].type == Type::TOKEN_ADD) {
				advance();
			} else {
				cont = false;
			}
		}
		return sign;
	}

	std::shared_ptr<Component> Parser::eatNumber(bool allowPm = false) {
		/*
		 * <integer> ::= <digit> <integer>? <digit>
		 * <number>  ::= <integer>? "." <integer>?
		 */

		size_t oldPos	 = m_pos;
		bool sign		 = false;
		bool integer	 = false;
		bool point		 = false;
		bool decimal	 = false;
		Int integerValue = 0;
		Real realValue	 = 0;

		if (finished()) goto skip;

		if (allowPm) sign = eatPlusMinus();

		if (finished()) goto skip;

		// Check for integer part (not required -- ".5" will work)
		if (m_lexer.tokens()[m_pos].type == Type::TYPE_NUMBER) {
			// Set integer part to this value
			std::stringstream stream;
			stream << m_lexer.tokens()[m_pos].value;
			stream >> integerValue;
			realValue = static_cast<Real>(integerValue);
			integer	  = true;
			advance();
		}

		if (finished()) goto skip;

		// Check for decimal point
		if (m_lexer.tokens()[m_pos].type == Type::TOKEN_POINT) {
			point = true;
			advance();
		}

		if (finished()) goto skip;

		// Check for decimal part
		if (m_lexer.tokens()[m_pos].type == Type::TYPE_NUMBER) {
			std::stringstream stream;
			stream << m_lexer.tokens()[m_pos - 2].value << "." << m_lexer.tokens()[m_pos].value;
			stream >> realValue;
			decimal = true;
			advance();
		}

	skip:

		if (!integer && !decimal) {
			// Update the old position to prevent misleading calculations
			m_pos = oldPos;
			return nullptr;
		}

		if (!point) { return std::make_shared<Integer>(sign ? -integerValue : integerValue); }
		return std::make_shared<Number>(sign ? -realValue : realValue);
	}

	std::shared_ptr<Component> Parser::eatVariable(bool allowPm) {
		/*
		 * <variable> ::= <identifier>
		 */

		size_t oldPos		= m_pos;
		std::string varName = "NONE";
		bool sign			= false;

		if (finished()) goto skip;

		if (allowPm) sign = eatPlusMinus();

		if (finished()) goto skip;

		if (m_lexer.tokens()[m_pos].type == Type::TYPE_SYMBOL) {
			varName = m_lexer.tokens()[m_pos].value;
			advance();
		}

	skip:

		if (varName == "NONE") {
			// Update the old position to prevent misleading calculations
			m_pos = oldPos;
			return nullptr;
		}

		auto variable = std::make_shared<Variable>(varName);
		if (sign) { return std::make_shared<OperatorNegate>(variable); }
		return variable;
	}

	std::shared_ptr<Component> Parser::eatFunction() {
		/*
		 * <function> ::= <functionName> <factor>
		 */

		if (std::vector<detail::Token> tokens = m_lexer.tokens();
			!finished() && static_cast<int32_t>(tokens[m_pos].type) & FUNCTION) {
			Type functionType = tokens[m_pos].type;
			advance();
			auto operand = eatFactor();
			if (!operand) { return nullptr; }

			switch (functionType) {
				case Type::FUNCTION_SIN: return std::make_shared<FunctionSin>(operand);
				case Type::FUNCTION_COS: return std::make_shared<FunctionCos>(operand);
				case Type::FUNCTION_TAN: return std::make_shared<FunctionTan>(operand);
				case Type::FUNCTION_ASIN: return std::make_shared<FunctionAsin>(operand);
				case Type::FUNCTION_ACOS: return std::make_shared<FunctionAcos>(operand);
				case Type::FUNCTION_ATAN: return std::make_shared<FunctionAtan>(operand);
				case Type::FUNCTION_SINH: return std::make_shared<FunctionSinh>(operand);
				case Type::FUNCTION_COSH: return std::make_shared<FunctionCosh>(operand);
				case Type::FUNCTION_TANH: return std::make_shared<FunctionTanh>(operand);
				case Type::FUNCTION_ASINH: return std::make_shared<FunctionAsinh>(operand);
				case Type::FUNCTION_ACOSH: return std::make_shared<FunctionAcosh>(operand);
				case Type::FUNCTION_ATANH: return std::make_shared<FunctionAtanh>(operand);
				case Type::FUNCTION_LOG: return std::make_shared<FunctionLog>(operand);
				case Type::FUNCTION_LOG2: return std::make_shared<FunctionLog2>(operand);
				case Type::FUNCTION_LOG10: return std::make_shared<FunctionLog10>(operand);
				case Type::FUNCTION_EXP: return std::make_shared<FunctionExp>(operand);
				case Type::FUNCTION_SQRT: return std::make_shared<FunctionSqrt>(operand);
				default: return nullptr;
			}
		}

		return nullptr;
	}

	std::shared_ptr<Component> Parser::eatFactor() {
		/*
		 * <factor> ::= <number>
		 * <factor> ::= <variable>
		 * <factor> ::= <factor> "^" <factor>
		 * <factor> ::= "(" <expression> ")"
		 * <factor> ::= <function> "(" expression ")"
		 */

		std::vector<detail::Token> tokens  = m_lexer.tokens();
		std::shared_ptr<Component> res	   = nullptr;
		std::shared_ptr<Function> function = nullptr;

		// Check for a number
		if (auto number = eatNumber(true); number) { res = number; }

		// Check for a variable if a number was not found
		if (!res) {
			if (auto variable = eatVariable(true); variable) { res = variable; }
		}

		if (!res && static_cast<int32_t>(tokens[m_pos].type) & FUNCTION) {
			// Eat a function
			if (auto func = eatFunction(); func) { res = func; }
		}

		if (!res && !finished() && tokens[m_pos].type == Type::TOKEN_LPAREN) {
			advance();
			res = eatExpression();
			advance();
		}

		if (!finished() && tokens[m_pos].type == Type::TOKEN_POW) {
			advance();
			function = std::make_shared<FunctionPow>();
		}

		if (function && res) {
			function->left()  = res;
			function->right() = eatFactor();
			if (!function->right()) { throwError("Syntax Error: Expected a factor"); }
			res = function;
		}

		return res;
	}

	std::shared_ptr<Component> Parser::eatTerm() {
		/*
		 * <term> ::= <factor> [*, /] <factor>
		 */

		std::vector<detail::Token> tokens = m_lexer.tokens();

		std::shared_ptr<Component> node = eatFactor();

		if (!node) { return nullptr; }

		while (continueTerm()) {
			std::shared_ptr<Function> function;

			if (tokens[m_pos].type == Type::TOKEN_MUL) {
				advance();
				function = std::make_shared<OperatorMul>();
			} else if (tokens[m_pos].type == Type::TOKEN_DIV) {
				advance();
				function = std::make_shared<OperatorDiv>();
			} else {
				throwError("Invalid Syntax. Expected * or /");
			}

			std::shared_ptr<Component> rhs = eatFactor();

			if (!rhs) { throwError("Invalid Syntax. Expected a factor"); }

			function->left()  = node;
			function->right() = rhs;
			node			  = function;
		}

		return node;
	}

	std::shared_ptr<Component> Parser::eatExpression() {
		/*
		 * <term> ::= <term> [+, -] <term>
		 */

		std::vector<detail::Token> tokens = m_lexer.tokens();

		std::shared_ptr<Component> term = eatTerm();

		if (!term) { return nullptr; }

		while (continueExpression()) {
			std::shared_ptr<Function> function;

			if (tokens[m_pos].type == Type::TOKEN_ADD) {
				advance();
				function = std::make_shared<OperatorAdd>();
			} else if (tokens[m_pos].type == Type::TOKEN_SUB) {
				advance();
				function = std::make_shared<OperatorSub>();
			} else {
				throwError("Invalid Syntax. Expected + or ^");
			}

			std::shared_ptr<Component> rhs = eatTerm();

			if (!rhs) { throwError("Invalid Syntax. Expected a term"); }

			function->left()  = term;
			function->right() = rhs;
			term			  = function;
		}

		return term;
	}

	void Parser::throwError(const std::string &message) const {
		int64_t pos = 0;
		for (size_t i = 0; i < m_pos; ++i) { pos += m_lexer.tokens()[i].value.length(); }
		throw error::SyntaxError(error::constructErrorMessage(message, m_lexer.str(), pos));
	}

	bool Parser::continueTerm() const {
		std::vector<detail::Token> tokens = m_lexer.tokens();

		if (finished()) return false;

		if (tokens[m_pos].type == Type::TOKEN_POW || tokens[m_pos].type == Type::TOKEN_MUL ||
			tokens[m_pos].type == Type::TOKEN_DIV) {
			return true;
		}

		return false;
	}

	bool Parser::continueExpression() const {
		std::vector<detail::Token> tokens = m_lexer.tokens();

		if (finished()) return false;

		if (tokens[m_pos].type == Type::TOKEN_ADD || tokens[m_pos].type == Type::TOKEN_SUB) {
			return true;
		}

		return false;
	}

	bool Parser::finished() const { return m_pos >= m_lexer.tokens().size(); }
} // namespace symbo
