#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Log10, LOG10, SYMBO_MATH_LIB::log10)

	std::shared_ptr<Component> FunctionLog10::differentiate(const RespectTo &respect) const {
		throw error::DerivativeError("Log10 cannot currently be differentiated");
	}
} // namespace symbo
