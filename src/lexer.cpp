#include <symbo/symbo.hpp>
#include <symbo/lexer.hpp>

namespace symbo {
	namespace detail {
		// Tokens must be listed from longest to shortest to avoid ambiguity
		const std::vector<Token> tokens = {
		  {Type::TOKEN_GE, ">="},	  {Type::TOKEN_LE, "<="},		{Type::TOKEN_EQ, "=="},
		  {Type::TOKEN_LPAREN, "("},  {Type::TOKEN_RPAREN, ")"},	{Type::TOKEN_LSQUARE, "["},
		  {Type::TOKEN_RSQUARE, "]"}, {Type::TOKEN_LCURLY, "{"},	{Type::TOKEN_RCURLY, "}"},
		  {Type::TOKEN_COLON, ":"},	  {Type::TOKEN_SEMICOLON, ";"}, {Type::TOKEN_POINT, "."},
		  {Type::TOKEN_COMMA, ","},	  {Type::TOKEN_DQUOTE, "\""},	{Type::TOKEN_SQUOTE, "'"},
		  {Type::TOKEN_ADD, "+"},	  {Type::TOKEN_SUB, "-"},		{Type::TOKEN_MUL, "*"},
		  {Type::TOKEN_DIV, "/"},	  {Type::TOKEN_POW, "^"},		{Type::TOKEN_MOD, "%"},
		  {Type::TOKEN_LT, "<"},	  {Type::TOKEN_GT, ">"},		{Type::TOKEN_EXCLAMATION, "!"},
		};

		// Don't have to be in order, but must be unique
		const std::vector<Token> functionTokens = {
		  {Type::FUNCTION_SIN, "sin"},	   {Type::FUNCTION_COS, "cos"},
		  {Type::FUNCTION_TAN, "tan"},	   {Type::FUNCTION_ASIN, "asin"},
		  {Type::FUNCTION_ACOS, "acos"},   {Type::FUNCTION_ATAN, "atan"},
		  {Type::FUNCTION_SINH, "sinh"},   {Type::FUNCTION_COSH, "cosh"},
		  {Type::FUNCTION_TANH, "tanh"},   {Type::FUNCTION_ASINH, "asinh"},
		  {Type::FUNCTION_ACOSH, "acosh"}, {Type::FUNCTION_ATANH, "atanh"},

		  {Type::FUNCTION_LOG, "log"},	   {Type::FUNCTION_LOG2, "log2"},
		  {Type::FUNCTION_LOG10, "log10"}, {Type::FUNCTION_EXP, "exp"},
		  {Type::FUNCTION_EXP2, "exp2"},   {Type::FUNCTION_EXP10, "exp10"},
		  {Type::FUNCTION_POW, "pow"},	   {Type::FUNCTION_SQRT, "sqrt"},
		};
	} // namespace detail

	Lexer::Lexer() = default;

	Lexer::Lexer(std::string str) : m_str(std::move(str)) {}

	std::string Lexer::str() const { return m_str; }

	std::vector<detail::Token> Lexer::tokens() const { return m_tokens; }

	void Lexer::clear() {
		m_str = "";
		m_tokens.clear();
		m_pos = 0;
	}

	void Lexer::reset() {
		m_tokens.clear();
		m_pos = 0;
	}

	void Lexer::advance(int64_t step) { m_pos += step; }

	// TODO: Split this into multiple smaller functions to clean up the algorithm
	void Lexer::tokenize() {
		if (m_pos == m_str.length()) return;

		std::vector<detail::Token> generated;
		m_pos = 0;

		while (m_pos < static_cast<int64_t>(m_str.length())) { // Loop over all tokens
			bool foundToken = false;

			// Search for a number or string literal
			int64_t endNumber;
			int64_t endString;
			bool number = findNumber(m_pos, endNumber);
			bool string = findString(m_pos, endString);

			if (number) {
				generated.emplace_back(
				  detail::Token {Type::TYPE_NUMBER, m_str.substr(m_pos, endNumber - m_pos)});
				advance(endNumber - m_pos);
				foundToken = true;
			} else if (string) {
				std::string value = m_str.substr(m_pos, endString - m_pos);

				// Variables and custom functions are looked up during evaluation
				// Only built-in functions are looked up during parsing

				// Look up built-in functions
				bool foundFunction = false;
				for (const auto &tok : detail::functionTokens) {
					if (value == tok.value) {
						generated.emplace_back(detail::Token {tok.type, tok.value});
						advance(endString - m_pos);
						foundFunction = true;
						break;
					}
				}

				if (!foundFunction) {
					generated.emplace_back(detail::Token {Type::TYPE_SYMBOL, value});
					advance(endString - m_pos);
				}

				foundToken = true;
			}

			if (!foundToken) {
				for (const auto &tok : detail::tokens) {
					// Search for a specific token in the string
					if (m_str.substr(m_pos, tok.value.length()) == tok.value) {
						generated.emplace_back(detail::Token {tok.type, tok.value});
						advance(static_cast<int64_t>(tok.value.length()));
						foundToken = true;
						break;
					}
				}
			}

			if (!foundToken) {
				// If no token was found, run some checks

				// If whitespace, ignore
				if (std::isspace(m_str[m_pos])) {
					advance();
				} else {
					// If not whitespace, throw an error
					throw error::TokenError(std::string("Unknown token: ") + m_str[m_pos]);
				}
			}
		}

		m_str = std::string();
		for (const auto &tok : generated) { m_str += tok.value; }

		m_tokens.clear();
		m_tokens = generated;
		// m_pos = m_str.length();
	}

	void Lexer::postProcess() {
		// Insert implicit multiplication operators

		for (size_t i = 0; i < m_tokens.size() - 1; ++i) {
			auto a = m_tokens[i].type;
			auto b = m_tokens[i + 1].type;

			bool numberVariable = a == Type::TYPE_NUMBER && b == Type::TYPE_SYMBOL;
			bool typeParen = ((static_cast<int32_t>(a) & FUNCTION) == 0) && b == Type::TOKEN_LPAREN;
			bool parenType = a == Type::TOKEN_RPAREN &&
							 ((static_cast<int32_t>(b) & FUNCTION) == 0) && b != Type::TOKEN_RPAREN;

			if (numberVariable || typeParen || parenType) {
				++i;
				m_tokens.insert(m_tokens.begin() + i, detail::Token {Type::TOKEN_MUL, "*"});
			}
		}
	}

	bool Lexer::findNumber(int64_t start, int64_t &end) const {
		int64_t current = start;

		while (m_str[current] >= '0' && m_str[current] <= '9') { current++; }

		if (current > start) {
			end = current;
			return true;
		}

		end = -1;
		return false;
	}

	bool Lexer::findString(int64_t start, int64_t &end) const {
		int64_t current = start;

		while ((m_str[current] >= 'a' && m_str[current] <= 'z') || m_str[current] == '_') {
			current++;
		}

		if (current > start) {
			end = current;
			return true;
		}

		end = -1;
		return false;
	}
} // namespace symbo
