#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Sinh, SINH, SYMBO_MATH_LIB::sinh)

	std::shared_ptr<Component> FunctionSinh::differentiate(const RespectTo &respect) const {
		throw error::DerivativeError("Sinh cannot currently be differentiated");
	}
} // namespace symbo
