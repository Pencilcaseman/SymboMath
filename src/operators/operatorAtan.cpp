#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Atan, ATAN, SYMBO_MATH_LIB::atan)

	std::shared_ptr<Component> FunctionAtan::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
