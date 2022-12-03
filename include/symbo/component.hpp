#pragma once

namespace symbo {
	class Component {
	public:
		Component();

		[[nodiscard]] virtual int64_t depth() const;
		[[nodiscard]] virtual Real eval() const;
		[[nodiscard]] virtual Int evalInt() const;
		[[nodiscard]] virtual std::string str(uint64_t indent) const;
		[[nodiscard]] virtual Type type() const;
	};
} // namespace symbo