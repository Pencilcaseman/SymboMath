#include <symbo/symbo.hpp>
#include <symbo/error.hpp>

namespace symbo::error {
	TokenError::TokenError(std::string message) : m_message(std::move(message)) {}
	[[nodiscard]] const char *TokenError::what() const noexcept { return m_message.c_str(); }

	TypeError::TypeError(std::string message) : m_message(std::move(message)) {}
	[[nodiscard]] const char *TypeError::what() const noexcept { return m_message.c_str(); }

	SyntaxError::SyntaxError(std::string message) : m_message(std::move(message)) {}
	[[nodiscard]] const char *SyntaxError::what() const noexcept { return m_message.c_str(); }
} // namespace symbo::error
