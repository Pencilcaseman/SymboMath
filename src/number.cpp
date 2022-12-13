#include <symbo/symbo.hpp>
#include <symbo/component.hpp>

namespace symbo {
	Integer::Integer() : m_value(0) {};
	Integer::Integer(const Real &value) : m_value(static_cast<Int>(value)) {}
	Integer::Integer(const Int &value) : m_value(value) {}

	int64_t Integer::depth() const { return 1; }

	Real Integer::eval() const { return static_cast<Real>(m_value); }

	int64_t Integer::evalInt() const { return m_value; }

	std::shared_ptr<Component> Integer::differentiate(const RespectTo &respect) const {
		return std::make_shared<Integer>(static_cast<Int>(0));
	}

	std::string Integer::str(uint64_t indent) const {
		return std::string(indent, ' ') + "[ Integer ] " + SYMBO_TO_STRING(m_value);
	}

	Type Integer::type() const { return Type::TYPE_INTEGER; }

	Number::Number() : m_value(0) {};
	Number::Number(const Real &value) : m_value(value) {}

	int64_t Number::depth() const { return 1; }

	Real Number::eval() const { return m_value; }

	Int Number::evalInt() const {
		// Check if the stored value is an integer
		if (SYMBO_MATH_LIB::floor(m_value) == m_value) {
			return static_cast<Int>(SYMBO_MATH_LIB::floor(m_value));
		}

		throw error::TypeError("Real cannot be used in Integer context");
	}

	std::shared_ptr<Component> Number::differentiate(const RespectTo &respect) const {
		return std::make_shared<Number>(0);
	}

	std::string Number::str(uint64_t indent) const {
		return std::string(indent, ' ') + "[ Number ] " + SYMBO_TO_STRING(m_value);
	}

	Type Number::type() const { return Type::TYPE_NUMBER; }
} // namespace symbo
