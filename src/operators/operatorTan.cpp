#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Tan, TAN, SYMBO_MATH_LIB::tan)

	std::shared_ptr<Component> FunctionTan::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
