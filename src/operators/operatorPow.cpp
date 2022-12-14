#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_BINOP_IMPL_F(Pow, POW, SYMBO_MATH_LIB::pow)

	std::shared_ptr<Component> FunctionPow::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
