#pragma once

namespace symbo {
	struct Token {
		Type type;
		std::string value;
	};

	extern std::vector<Token> tokens;

	class Lexer {
	public:
		Lexer();
		explicit Lexer(std::string str);

		[[nodiscard]] std::string str() const;
		[[nodiscard]] std::vector<Token> tokens() const;

		void clear();

		void advance(int64_t step = 1);
		void tokenize();

		bool findNumber(int64_t start, int64_t &end) const;
		bool findString(int64_t start, int64_t &end) const;

	private:
		std::string m_str;
		int64_t m_pos;
		std::vector<Token> m_tokens;
	};
} // namespace symbo
