#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Atanh, ATANH, SYMBO_MATH_LIB::atanh)

	std::shared_ptr<Component> FunctionAtanh::differentiate(const RespectTo &respect) const {
		throw error::DerivativeError("Atanh cannot currently be differentiated");
	}
} // namespace symbo
