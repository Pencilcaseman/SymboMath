#pragma once

#define SYMBO_UNOP_HEADER(NAME_)                                                                   \
	class Function##NAME_ : public Function {                                                      \
	public:                                                                                        \
		Function##NAME_();                                                                         \
		explicit Function##NAME_(std::shared_ptr<Component> val);                                  \
                                                                                                   \
		[[nodiscard]] int64_t depth() const override;                                              \
                                                                                                   \
		[[nodiscard]] Real eval() const override;                                                  \
                                                                                                   \
		[[nodiscard]] std::string str(uint64_t indent) const override;                             \
                                                                                                   \
		[[nodiscard]] std::shared_ptr<Component> &left();                                          \
		[[nodiscard]] const std::shared_ptr<Component> &left() const;                              \
                                                                                                   \
		[[nodiscard]] Type type() const override;                                                  \
                                                                                                   \
	private:                                                                                       \
		std::shared_ptr<Component> m_val;                                                          \
	};

#define SYMBO_UNOP_HEADER_O(NAME_)                                                                 \
	class Operator##NAME_ : public Function {                                                      \
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
		[[nodiscard]] std::shared_ptr<Component> &left();                                          \
		[[nodiscard]] const std::shared_ptr<Component> &left() const;                              \
                                                                                                   \
		[[nodiscard]] Type type() const override;                                                  \
                                                                                                   \
	private:                                                                                       \
		std::shared_ptr<Component> m_val;                                                          \
	};

// Function call
#define SYMBO_UNOP_IMPL_F(NAME_, CAPS_, OP_)                                                       \
	Function##NAME_::Function##NAME_() : m_val(nullptr) {}                                         \
                                                                                                   \
	Function##NAME_::Function##NAME_(std::shared_ptr<Component> val) : m_val(std::move(val)) {}    \
                                                                                                   \
	int64_t Function##NAME_::depth() const { return m_val->depth() + 1; }                          \
                                                                                                   \
	Real Function##NAME_::eval() const { return OP_(m_val->eval()); }                              \
                                                                                                   \
	std::shared_ptr<Component> &Function##NAME_::left() { return m_val; }                          \
	const std::shared_ptr<Component> &Function##NAME_::left() const { return m_val; }              \
                                                                                                   \
	std::string Function##NAME_::str(uint64_t indent) const {                                      \
		if (indent > SYMBO_MAX_PRINT_DEPTH) return std::string(indent, ' ') + "...";               \
		std::string val = m_val->str(indent + 4);                                                  \
		return std::string(indent, ' ') + std::string("[ ") + STRINGIFY(NAME_) " ]\n" + val +      \
			   "\n";                                                                               \
	}                                                                                              \
                                                                                                   \
	Type Function##NAME_::type() const { return Type::FUNCTION_##CAPS_; }

// Operator call
#define SYMBO_UNOP_IMPL_O(NAME_, CAPS_, OP_)                                                       \
	Operator##NAME_::Operator##NAME_() : m_val(nullptr) {}                                         \
                                                                                                   \
	Operator##NAME_::Operator##NAME_(std::shared_ptr<Component> val) : m_val(std::move(val)) {}    \
                                                                                                   \
	int64_t Operator##NAME_::depth() const { return m_val->depth() + 1; }                          \
                                                                                                   \
	Real Operator##NAME_::eval() const { return OP_(m_val->eval()); }                              \
                                                                                                   \
	std::string Operator##NAME_::str(uint64_t indent) const {                                      \
		if (indent > SYMBO_MAX_PRINT_DEPTH) return std::string(indent, ' ') + "...";               \
		std::string val = m_val->str(indent + 4);                                                  \
		return std::string(indent, ' ') + std::string("[ ") + STRINGIFY(NAME_) " ]\n" + val +      \
			   "\n";                                                                               \
	}                                                                                              \
                                                                                                   \
	Type Operator##NAME_::type() const { return Type::OPERATOR_##CAPS_; }
