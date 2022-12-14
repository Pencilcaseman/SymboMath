#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_BINOP_IMPL_O(Div, DIV, /)

	std::shared_ptr<Component> OperatorDiv::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
