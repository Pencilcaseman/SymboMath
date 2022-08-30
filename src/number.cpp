#include <symbo/symbo.hpp>
#include <symbo/component.hpp>

namespace symbo {
	Number::Number() : m_value(0) {};
	Number::Number(const Scalar &value) : m_value(value) {}

	int64_t Number::depth() const { return 1; }

	Scalar Number::eval() const { return m_value; }

	std::string Number::str(uint64_t indent) const { return SYMBO_TO_STRING(m_value); }

	Type Number::type() const { return Type::NUMBER; }
} // namespace symbo
