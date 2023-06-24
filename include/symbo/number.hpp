#pragma once

namespace symbo {
	class Integer : public Component {
	public:
		Integer();
		explicit Integer(const Real &value);
		explicit Integer(const Int &value);

		[[nodiscard]] int64_t depth() const override;

		[[nodiscard]] Real eval() const override;

		[[nodiscard]] Int evalInt() const override;

		[[nodiscard]] std::shared_ptr<Component>
		differentiate(const RespectTo &respect) const override;

		[[nodiscard]] std::string str(uint64_t indent) const override;

		[[nodiscard]] Type type() const override;

	private:
		Int m_value;
	};

	class Number : public Component {
	public:
		Number();
		explicit Number(const Real &value);

		[[nodiscard]] int64_t depth() const override;

		[[nodiscard]] Real eval() const override;

		[[nodiscard]] Int evalInt() const override;

		[[nodiscard]] std::shared_ptr<Component>
		differentiate(const RespectTo &respect) const override;

		[[nodiscard]] std::string str(uint64_t indent) const override;

		[[nodiscard]] Type type() const override;

	private:
		Real m_value;
	};
} // namespace symbo
