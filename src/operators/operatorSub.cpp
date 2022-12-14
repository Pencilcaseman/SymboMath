#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_BINOP_IMPL_O(Sub, SUB, -)

	std::shared_ptr<Component> OperatorSub::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
