#pragma once

#define SYMBO_BINOP_HEADER(NAME_)                                                                  \
	class Operator##NAME_ : public Function {                                                      \
	public:                                                                                        \
		Operator##NAME_();                                                                         \
		Operator##NAME_(std::shared_ptr<Component> left, std::shared_ptr<Component> right);        \
                                                                                                   \
		[[nodiscard]] int64_t depth() const override;                                              \
                                                                                                   \
		[[nodiscard]] Real eval() const override;                                                  \
                                                                                                   \
		[[nodiscard]] Int evalInt() const override;                                                \
                                                                                                   \
		[[nodiscard]] std::string str(uint64_t indent) const override;                             \
                                                                                                   \
		[[nodiscard]] Type type() const override;                                                  \
	};

// Operator call
#define SYMBO_BINOP_IMPL_O(NAME_, CAPS_, OP_)                                                      \
	Operator##NAME_::Operator##NAME_() : Function(nullptr, nullptr) {}                             \
                                                                                                   \
	Operator##NAME_::Operator##NAME_(                                                              \
	  std::shared_ptr<Component> left, std::shared_ptr<Component> right) :                         \
			Function(left, right) {}                                                                \
                                                                                                   \
	int64_t Operator##NAME_::depth() const {                                                       \
		return std::max(m_left->depth(), m_right->depth()) + 1;                                    \
	}                                                                                              \
                                                                                                   \
	Real Operator##NAME_::eval() const { return m_left->eval() OP_ m_right->eval(); }              \
                                                                                                   \
	Int Operator##NAME_::evalInt() const { return m_left->evalInt() OP_ m_right->evalInt(); }      \
                                                                                                   \
	std::string Operator##NAME_::str(uint64_t indent) const {                                      \
		std::string left  = m_left->str(indent + 4);                                               \
		std::string right = m_right->str(indent + 4);                                              \
		return std::string(indent, ' ') + "[ Function ] " + std::string("[ ") +                    \
			   STRINGIFY(NAME_) " ]\n" + left + "\n" + right;                                      \
	}                                                                                              \
                                                                                                   \
	Type Operator##NAME_::type() const { return Type::OPERATOR_##CAPS_; }

// Function call
#define SYMBO_BINOP_IMPL_F(NAME_, CAPS_, OP_)                                                      \
	Operator##NAME_::Operator##NAME_() : Function(nullptr, nullptr) {}                             \
                                                                                                   \
	Operator##NAME_::Operator##NAME_(                                                              \
	  std::shared_ptr<Component> left, std::shared_ptr<Component> right) :                         \
			Function(left, right) {}                                                               \
                                                                                                   \
	int64_t Operator##NAME_::depth() const {                                                       \
		return std::max(m_left->depth(), m_right->depth()) + 1;                                    \
	}                                                                                              \
                                                                                                   \
	Real Operator##NAME_::eval() const { return OP_(m_left->eval(), m_right->eval()); }            \
                                                                                                   \
	Int Operator##NAME_::evalInt() const {                                                         \
		return static_cast<Int>(OP_(m_left->evalInt(), m_right->evalInt()));                       \
	}                                                                                              \
                                                                                                   \
	std::string Operator##NAME_::str(uint64_t indent) const {                                      \
		std::string left  = m_left->str(indent + 4);                                               \
		std::string right = m_right->str(indent + 4);                                              \
		return std::string(indent, ' ') + "[ Function ] " + std::string("[ ") +                    \
			   STRINGIFY(NAME_) " ]\n" + left + "\n" + right;                                      \
	}                                                                                              \
                                                                                                   \
	Type Operator##NAME_::type() const { return Type::OPERATOR_##CAPS_; }
