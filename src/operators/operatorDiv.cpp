#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_BINOP_IMPL_O(Div, DIV, /)

	std::shared_ptr<Component> OperatorDiv::differentiate(const RespectTo &respect) const {
		return std::make_shared<OperatorDiv>(
		  std::make_shared<OperatorSub>(
			std::make_shared<OperatorMul>(m_left->differentiate(respect), m_right),
			std::make_shared<OperatorMul>(m_left, m_right->differentiate(respect))),
		  std::make_shared<FunctionPow>(m_right, std::make_shared<Number>(2)));
	}
} // namespace symbo
