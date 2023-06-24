#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_O(Negate, NEGATE, -)

	std::shared_ptr<Component> OperatorNegate::differentiate(const RespectTo &respect) const {
		return std::make_shared<OperatorNegate>(m_val->differentiate(respect));
	}
} // namespace symbo
