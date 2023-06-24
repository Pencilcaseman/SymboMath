#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_BINOP_IMPL_O(Add, ADD, +)

	std::shared_ptr<Component> OperatorAdd::differentiate(const RespectTo &respect) const {
		return std::make_shared<OperatorAdd>(m_left->differentiate(respect),
											 m_right->differentiate(respect));
	}
} // namespace symbo
