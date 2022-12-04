#include <utility>

#pragma once

namespace symbo {
	namespace detail {
		struct Token {
			Type type;
			std::string value;
		};

		extern const std::vector<Token> tokens;
		extern const std::vector<Token> functionTokens;
	} // namespace detail

	class Lexer {
	public:
		Lexer();

		explicit Lexer(std::string str);

		[[nodiscard]] std::string str() const;

		[[nodiscard]] std::vector<detail::Token> tokens() const;

		void clear();

		void reset();

		void advance(int64_t step = 1);

		void tokenize();

		bool findNumber(int64_t start, int64_t &end) const;

		bool findString(int64_t start, int64_t &end) const;

	private:
		std::string m_str;
		int64_t m_pos = 0;
		std::vector<detail::Token> m_tokens;
	};
} // namespace symbo
