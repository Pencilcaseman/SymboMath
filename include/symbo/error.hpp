#pragma once

namespace symbo::error {
	/**
	 * An invalid token was encountered while tokenizing
	 */
	class TokenError : public std::exception {
	public:
		/**
		 * Construct a new TokenError
		 * @param message The error message to construct with
		 */
		explicit TokenError(std::string message);

		/**
		 * Return the error message as a C string
		 * @return The error message as a C string
		 */
		[[nodiscard]] const char *what() const noexcept override;

	private:
		std::string m_message;
	};

	class TypeError : public std::exception {
	public:
		/**
		 * Construct a new TypeError
		 * @param message The error message to construct with
		 */
		explicit TypeError(std::string message);

		/**
		 * Return the error message as a C string
		 */
		[[nodiscard]] const char *what() const noexcept override;

	private:
		std::string m_message;
	};

	class SyntaxError : public std::exception {
	public:
		/**
		 * Construct a new TypeError
		 * @param message The error message to construct with
		 */
		explicit SyntaxError(std::string message);

		/**
		 * Return the error message as a C string
		 */
		[[nodiscard]] const char *what() const noexcept override;

	private:
		std::string m_message;
	};
} // namespace symbo::error