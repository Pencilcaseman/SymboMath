#include <symbo/symbo.hpp>
#include <symbo/parser.hpp>

namespace symbo {
	Parser::Parser(std::string string) : m_string(std::move(string)), m_lexer(m_string) {}

	std::string Parser::str() const { return m_string; }
	Lexer Parser::lexer() const { return m_lexer; }
	std::shared_ptr<Component> Parser::tree() const { return m_tree; }

	void Parser::advance(int64_t dist) { m_pos += dist; }

	void Parser::parse() {
		m_lexer.tokenize();
		const std::vector<detail::Token> tokens = m_lexer.tokens();

		bool lParen							= false;
		bool rParen							= false;
		std::shared_ptr<Function> operation = nullptr;
		std::shared_ptr<Component> variable = nullptr;
		std::shared_ptr<Component> number	= nullptr;

		// Eat tokens one-by-one, interpreting their meaning appropriately
		while (m_pos < tokens.size()) {
			// Check for numbers, variables and other tokens
			// operation = m_pos > 0 ? eatOperation() : nullptr;
			number = eatNumber(lParen || rParen || operation || m_pos == 0);
		}
	}

	std::shared_ptr<Component> Parser::eatNumber(bool allowPm = false) {
		bool sign		 = false;
		bool integer	 = false;
		bool point		 = false;
		bool decimal	 = false;
		Int integerValue = 0;
		Real realValue	 = 0;

		// Check for +/- in front of the number
		if (allowPm) {
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
		}

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
		if (!integer && !decimal) return nullptr;
		if (!point) { return std::make_shared<Integer>(sign ? -integerValue : integerValue); }
		return std::make_shared<Number>(sign ? -realValue : realValue);
	}

	bool Parser::finished() const { return m_pos >= m_lexer.tokens().size(); }
} // namespace symbo
