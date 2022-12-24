#include <symbo/symbo.hpp>
#include <symbo/error.hpp>

namespace symbo::error {
	TokenError::TokenError(std::string message) : m_message(std::move(message)) {}
	[[nodiscard]] const char *TokenError::what() const noexcept { return m_message.c_str(); }

	TypeError::TypeError(std::string message) : m_message(std::move(message)) {}
	[[nodiscard]] const char *TypeError::what() const noexcept { return m_message.c_str(); }

	SyntaxError::SyntaxError(std::string message) : m_message(std::move(message)) {}
	[[nodiscard]] const char *SyntaxError::what() const noexcept { return m_message.c_str(); }

	DerivativeError::DerivativeError(std::string message) : m_message(std::move(message)) {}
	[[nodiscard]] const char *DerivativeError::what() const noexcept { return m_message.c_str(); }

	std::string constructErrorMessage(const std::string &msg, const std::string &line,
									  int64_t pos) {
		return msg + "\nError occurred here: " + line + "\n" + std::string(21 + pos, '~') + "^";
	}
} // namespace symbo::error
