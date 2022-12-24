#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Cosh, COSH, SYMBO_MATH_LIB::cosh)

	std::shared_ptr<Component> FunctionCosh::differentiate(const RespectTo &respect) const {
		throw error::DerivativeError("Cosh cannot currently be differentiated");
	}
} // namespace symbo
