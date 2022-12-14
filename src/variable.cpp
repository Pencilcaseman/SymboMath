#include <symbo/symbo.hpp>
#include <symbo/component.hpp>
#include <utility>

namespace symbo {
	Variable::Variable() : m_name("UNNAMED") {}
	Variable::Variable(std::string name) : m_name(std::move(name)) {}

	int64_t Variable::depth() const { return 1; }

	std::shared_ptr<Component> Variable::differentiate(const RespectTo &respect) const {
		if (m_name == respect.to()) {
			return std::make_shared<Number>(1);
		} else {
			return std::make_shared<Number>(0);
		}
	}

	std::string Variable::str(uint64_t indent) const {
		return std::string(indent, ' ') + "[ Variable ] " + m_name;
	}

	Type Variable::type() const { return Type::TYPE_SYMBOL; }
} // namespace symbo
