#include <symbo/symbo.hpp>
#include <symbo/respectTo.hpp>

namespace symbo {
	std::string &RespectTo::to() { return m_to; }

	const std::string &RespectTo::to() const { return m_to; }
} // namespace symbo