#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Sqrt, SQRT, SYMBO_MATH_LIB::sqrt)

	std::shared_ptr<Component> FunctionSqrt::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
