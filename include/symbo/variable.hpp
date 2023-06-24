#pragma once

namespace symbo {
	class Variable : public Component {
	public:
		Variable();
		explicit Variable(std::string name);

		[[nodiscard]] int64_t depth() const override;

		[[nodiscard]] std::shared_ptr<Component>
		differentiate(const RespectTo &respect) const override;

		[[nodiscard]] std::string str(uint64_t indent) const override;

		[[nodiscard]] Type type() const override;

	private:
		std::string m_name;
	};
} // namespace symbo
