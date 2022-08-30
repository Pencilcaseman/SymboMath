#pragma once

namespace symbo {
	class Number : public Component {
	public:
		Number();
		explicit Number(const Scalar &value);

		[[nodiscard]] int64_t depth() const override;

		[[nodiscard]] Scalar eval() const override;

		[[nodiscard]] std::string str(uint64_t indent) const override;

		[[nodiscard]] Type type() const override;

	private:
		Scalar m_value;
	};
} // namespace symbo
