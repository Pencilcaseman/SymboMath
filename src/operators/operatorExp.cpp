#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Exp, EXP, SYMBO_MATH_LIB::exp)

	std::shared_ptr<Component> FunctionExp::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
