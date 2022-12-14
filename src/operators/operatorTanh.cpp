#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Tanh, TANH, SYMBO_MATH_LIB::tanh)

	std::shared_ptr<Component> FunctionTanh::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
