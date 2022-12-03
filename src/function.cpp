#include <symbo/symbo.hpp>
#include <symbo/function.hpp>

namespace symbo {
	Function::Function(const std::shared_ptr<Component> &left,
					   const std::shared_ptr<Component> &right) :
			m_left(left),
			m_right(right) {}

	std::shared_ptr<Component> Function::left() const { return m_left; }
	std::shared_ptr<Component> Function::right() const { return m_right; }
} // namespace symbo
