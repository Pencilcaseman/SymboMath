#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Log2, LOG2, SYMBO_MATH_LIB::log2)

	std::shared_ptr<Component> FunctionLog2::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
