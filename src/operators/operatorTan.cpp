#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Tan, TAN, SYMBO_MATH_LIB::tan)

	std::shared_ptr<Component> FunctionTan::differentiate(const RespectTo &respect) const {
		return std::make_shared<OperatorDiv>(
		  m_val->differentiate(respect),
		  std::make_shared<FunctionPow>(std::make_shared<FunctionCos>(m_val),
										std::make_shared<Number>(2)));
	}
} // namespace symbo
