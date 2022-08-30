#include <symbo/symbo.hpp>
#include <symbo/component.hpp>

namespace symbo {
	Component::Component() = default;

	int64_t Component::depth() const {
		throw std::invalid_argument("depth() not implemented for type " + typeToString(type()));
	}

	Scalar Component::eval() const {
		throw std::invalid_argument("eval() not implemented for type " + typeToString(type()));
	}

	std::string Component::str(uint64_t indent) const {
		return std::string(indent, ' ') + "[ Component ] " + "UNDEFINED";
	}

	Type Component::type() const { return Type::COMPONENT; }
} // namespace symbo
