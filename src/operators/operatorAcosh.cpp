#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Acosh, ACOSH, SYMBO_MATH_LIB::acosh)

	std::shared_ptr<Component> FunctionAcosh::differentiate(const RespectTo &respect) const {
		throw error::DerivativeError("Acosh cannot currently be differentiated");
	}
} // namespace symbo
