#pragma once

#define SYMBO_UNOP_HEADER(NAME_)                                                                   \
	class Operator##NAME_ : public Component {                                                     \
	public:                                                                                        \
		Operator##NAME_();                                                                         \
		explicit Operator##NAME_(std::shared_ptr<Component> val);                                  \
                                                                                                   \
		[[nodiscard]] int64_t depth() const override;                                              \
                                                                                                   \
		[[nodiscard]] Real eval() const override;                                                  \
                                                                                                   \
		[[nodiscard]] std::string str(uint64_t indent) const override;                             \
                                                                                                   \
		[[nodiscard]] Type type() const override;                                                  \
                                                                                                   \
	private:                                                                                       \
		std::shared_ptr<Component> m_val;                                                          \
	};

#define SYMBO_UNOP_IMPL(NAME_, CAPS_, OP_)                                                         \
	Operator##NAME_::Operator##NAME_() : m_val(nullptr) {}                                         \
                                                                                                   \
	Operator##NAME_::Operator##NAME_(std::shared_ptr<Component> val) : m_val(std::move(val)) {}    \
                                                                                                   \
	int64_t Operator##NAME_::depth() const { return m_val->depth() + 1; }                          \
                                                                                                   \
	Real Operator##NAME_::eval() const { return OP_(m_val->eval()); }                              \
                                                                                                   \
	std::string Operator##NAME_::str(uint64_t indent) const {                                      \
		std::string val = m_val->str(indent + 4);                                                  \
		return std::string("[ ") + STRINGIFY(NAME_) " ]\n" + val + "\n";                           \
	}                                                                                              \
                                                                                                   \
	Type Operator##NAME_::type() const { return Type::OPERATOR_##CAPS_; }
