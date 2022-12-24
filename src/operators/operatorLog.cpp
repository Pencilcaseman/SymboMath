#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	SYMBO_UNOP_IMPL_F(Log, LOG, SYMBO_MATH_LIB::log)

	std::shared_ptr<Component> FunctionLog::differentiate(const RespectTo &respect) const {
		return std::make_shared<OperatorDiv>(m_val->differentiate(respect), m_val);
	}
} // namespace symbo
