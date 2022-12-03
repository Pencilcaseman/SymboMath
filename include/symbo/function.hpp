#pragma once

namespace symbo {
	class Function : public Component {
	public:
		Function() = default;

		explicit Function(const std::shared_ptr<Component> &left,
						  const std::shared_ptr<Component> &right);

		[[nodiscard]] std::shared_ptr<Component> left() const;
		[[nodiscard]] std::shared_ptr<Component> right() const;

	protected:
		std::shared_ptr<Component> m_left  = nullptr;
		std::shared_ptr<Component> m_right = nullptr;
	};
} // namespace symbo
