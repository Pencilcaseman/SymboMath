#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Acos, ACOS, SYMBO_MATH_LIB::acos)

	std::shared_ptr<Component> FunctionAcos::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
