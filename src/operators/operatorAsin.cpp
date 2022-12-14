#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Asin, ASIN, SYMBO_MATH_LIB::asin)

	std::shared_ptr<Component> FunctionAsin::differentiate(const RespectTo &respect) const {
		return nullptr;
	}
} // namespace symbo
