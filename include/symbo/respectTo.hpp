#pragma once

namespace symbo {
	class RespectTo {
	public:
		RespectTo()								= default;
		RespectTo(const RespectTo &)			= default;
		RespectTo(RespectTo &&)					= default;
		RespectTo &operator=(const RespectTo &) = default;
		RespectTo(const std::string &to) : m_to(to) {}

		std::string &to();
		const std::string &to() const;

	private:
		std::string m_to;
	};
} // namespace symbo
