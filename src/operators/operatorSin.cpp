#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Sin, SIN, SYMBO_MATH_LIB::sin)

	std::shared_ptr<Component> FunctionSin::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
