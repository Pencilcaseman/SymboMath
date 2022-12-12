#pragma once

namespace symbo {
	class Parser {
	public:
		explicit Parser(std::string string);

		Parser(const Parser &other) = default;

		Parser(Parser &&other) = default;

		Parser &operator=(const Parser &other) = default;

		Parser &operator=(Parser &&other) = default;

		[[nodiscard]] std::string str() const;

		[[nodiscard]] Lexer lexer() const;

		[[nodiscard]] std::shared_ptr<Component> tree() const;

		void advance(int64_t dist = 1);

		void clear();

		void reset();

		/**
		 * Run the parsing algorithm on the Parser object, populating the `m_tree` component of the
		 * object.
		 */
		void parse();

		[[nodiscard]] bool eatPlusMinus();

		[[nodiscard]] std::shared_ptr<Component> eatNumber(bool allowPm);

		[[nodiscard]] std::shared_ptr<Component> eatVariable(bool allowPm);

		[[nodiscard]] std::shared_ptr<Component> eatFactor();

		[[nodiscard]] std::shared_ptr<Component> eatFunction();

		[[nodiscard]] std::shared_ptr<Component> eatTerm();

		[[nodiscard]] std::shared_ptr<Component> eatExpression();

	private:
		[[nodiscard]] bool continueTerm() const;

		[[nodiscard]] bool continueExpression() const;

		[[nodiscard]] bool finished() const;

		std::string m_string;
		Lexer m_lexer;
		std::shared_ptr<Component> m_tree;
		size_t m_pos = 0;
	};
} // namespace symbo
