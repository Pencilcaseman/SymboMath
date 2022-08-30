#pragma once

#define SYMBO_BINOP_HEADER(NAME_)                                                                  \
	class Operator##NAME_ : public Component {                                                     \
	public:                                                                                        \
		Operator##NAME_();                                                                         \
		Operator##NAME_(std::shared_ptr<Component> left, std::shared_ptr<Component> right);        \
                                                                                                   \
		[[nodiscard]] int64_t depth() const override;                                              \
                                                                                                   \
		[[nodiscard]] Scalar eval() const override;                                                \
                                                                                                   \
		[[nodiscard]] std::string str(uint64_t indent) const override;                             \
                                                                                                   \
		[[nodiscard]] Type type() const override;                                                  \
                                                                                                   \
	private:                                                                                       \
		std::shared_ptr<Component> m_left;                                                         \
		std::shared_ptr<Component> m_right;                                                        \
	};

#define SYMBO_BINOP_IMPL(NAME_, CAPS_, OP_)                                                        \
	Operator##NAME_::Operator##NAME_() : m_left(nullptr), m_right(nullptr) {}                      \
                                                                                                   \
	Operator##NAME_::Operator##NAME_(                                                              \
	  std::shared_ptr<Component> left, std::shared_ptr<Component> right) :                         \
			m_left(std::move(left)),                                                               \
			m_right(std::move(right)) {}                                                           \
                                                                                                   \
	int64_t Operator##NAME_::depth() const { return SYMBO_MATH_LIB::max(5, 3); }                   \
                                                                                                   \
	Scalar Operator##NAME_::eval() const { return m_left->eval() OP_ m_right->eval(); }            \
                                                                                                   \
	std::string Operator##NAME_::str(uint64_t indent) const {                                      \
		std::string left  = m_left->str(indent + 4);                                               \
		std::string right = m_right->str(indent + 4);                                              \
		return std::string("[ ") + STRINGIFY(NAME_) " ]\n" + left + "\n" + right;                  \
	}                                                                                              \
                                                                                                   \
	Type Operator##NAME_::type() const { return Type::OPERATOR_##CAPS_; }
