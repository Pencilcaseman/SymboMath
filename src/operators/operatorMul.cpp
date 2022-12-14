#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_BINOP_IMPL_O(Mul, MUL, *)

	std::shared_ptr<Component> OperatorMul::differentiate(const RespectTo &respect) const {
		// Product rule

		std::shared_ptr<Component> df = m_left->differentiate(respect);
		std::shared_ptr<Component> dg = m_right->differentiate(respect);

		return std::make_shared<OperatorAdd>(std::make_shared<OperatorMul>(df, m_right),
											 std::make_shared<OperatorMul>(m_left, dg));
	}
} // namespace symbo
