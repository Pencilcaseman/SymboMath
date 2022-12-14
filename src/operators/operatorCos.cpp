#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Cos, COS, SYMBO_MATH_LIB::cos)

	std::shared_ptr<Component> FunctionCos::differentiate(const RespectTo &respect) const {
		return std::make_shared<OperatorNegate>(std::make_shared<OperatorMul>(
		  m_val->differentiate(respect), std::make_shared<FunctionSin>(m_val)));
	}
} // namespace symbo
