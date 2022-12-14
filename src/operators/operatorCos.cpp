#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Cos, COS, SYMBO_MATH_LIB::cos)

	std::shared_ptr<Component> FunctionCos::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
