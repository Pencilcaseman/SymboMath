#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Sin, SIN, SYMBO_MATH_LIB::sin)

	std::shared_ptr<Component> FunctionSin::differentiate(const RespectTo &respect) const {
		return std::make_shared<OperatorMul>(m_val->differentiate(respect),
											 std::make_shared<FunctionCos>(m_val));
	}
} // namespace symbo
