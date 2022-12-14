#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Asinh, ASINH, SYMBO_MATH_LIB::asinh)

	std::shared_ptr<Component> FunctionAsinh::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
