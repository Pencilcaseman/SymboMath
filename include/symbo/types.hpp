#pragma once

namespace symbo {
	constexpr uint32_t TYPE		= 1ull << 7;
	constexpr uint32_t TOKEN	= 1ull << 6;
	constexpr uint32_t OPERATOR = 1ull << 5;

	enum class Type {
		TYPE_COMPONENT = TYPE | 0, // Base class for all types
		TYPE_NUMBER	   = TYPE | 1, // A real value
		TYPE_INTEGER   = TYPE | 2, // A signed integer value
		TYPE_SYMBOL	   = TYPE | 3, // A symbol (variable)
		TYPE_FUNCTION  = TYPE | 4, // A user-defined function

		TOKEN_LPAREN	  = TOKEN | 0,	// (
		TOKEN_RPAREN	  = TOKEN | 1,	// )
		TOKEN_LSQUARE	  = TOKEN | 2,	// [
		TOKEN_RSQUARE	  = TOKEN | 3,	// ]
		TOKEN_LCURLY	  = TOKEN | 4,	// {
		TOKEN_RCURLY	  = TOKEN | 5,	// }
		TOKEN_COLON		  = TOKEN | 6,	// :
		TOKEN_SEMICOLON	  = TOKEN | 7,	// ;
		TOKEN_POINT		  = TOKEN | 8,	// .
		TOKEN_COMMA		  = TOKEN | 9,	// ,
		TOKEN_DQUOTE	  = TOKEN | 10, // "
		TOKEN_SQUOTE	  = TOKEN | 11, // '
		TOKEN_ADD		  = TOKEN | 12, // +
		TOKEN_SUB		  = TOKEN | 13, // -
		TOKEN_MUL		  = TOKEN | 14, // *
		TOKEN_DIV		  = TOKEN | 15, // /
		TOKEN_POW		  = TOKEN | 16, // ^
		TOKEN_MOD		  = TOKEN | 17, // %
		TOKEN_EQ		  = TOKEN | 18, // ==
		TOKEN_LT		  = TOKEN | 19, // <
		TOKEN_GT		  = TOKEN | 20, // >
		TOKEN_LE		  = TOKEN | 21, // <=
		TOKEN_GE		  = TOKEN | 22, // >=
		TOKEN_EXCLAMATION = TOKEN | 23, // !

		OPERATOR_PLUS  = OPERATOR | 0, // Unary plus
		OPERATOR_MINUS = OPERATOR | 1, // Unary minus

		OPERATOR_ADD = OPERATOR | 2, // Binary Addition
		OPERATOR_SUB = OPERATOR | 3, // Binary Subtraction
		OPERATOR_MUL = OPERATOR | 4, // Binary Multiplication
		OPERATOR_DIV = OPERATOR | 5, // Binary Division

		OPERATOR_NEGATE = OPERATOR | 6,	 // Negation
		OPERATOR_SIN	= OPERATOR | 7,	 // Sine
		OPERATOR_COS	= OPERATOR | 8,	 // Cosine
		OPERATOR_TAN	= OPERATOR | 9,	 // Tangent
		OPERATOR_ASIN	= OPERATOR | 10, // Arcsine
		OPERATOR_ACOS	= OPERATOR | 11, // Arccosine
		OPERATOR_ATAN	= OPERATOR | 12, // Arctangent
		OPERATOR_SINH	= OPERATOR | 13, // Hyperbolic Sine
		OPERATOR_COSH	= OPERATOR | 14, // Hyperbolic Cosine
		OPERATOR_TANH	= OPERATOR | 15, // Hyperbolic Tangent
		OPERATOR_ASINH	= OPERATOR | 16, // Hyperbolic Arcsine
		OPERATOR_ACOSH	= OPERATOR | 17, // Hyperbolic Arccosine
		OPERATOR_ATANH	= OPERATOR | 18, // Hyperbolic Arctangent

		OPERATOR_LOG   = OPERATOR | 19, // Log_e
		OPERATOR_LOG2  = OPERATOR | 20, // Log_10
		OPERATOR_LOG10 = OPERATOR | 21, // Log_10
		OPERATOR_EXP   = OPERATOR | 22, // e^x
		OPERATOR_EXP2  = OPERATOR | 23, // 2^x
		OPERATOR_EXP10 = OPERATOR | 24, // 10^x
		OPERATOR_POW   = OPERATOR | 25, // Binary Power (x^y)
		OPERATOR_SQRT  = OPERATOR | 26	// Square Root
	};

	std::string typeToString(const Type &type);
} // namespace symbo
