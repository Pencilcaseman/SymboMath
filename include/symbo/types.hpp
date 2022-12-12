#pragma once

namespace symbo {
	constexpr int32_t TYPE	   = 1l << 31;
	constexpr int32_t TOKEN	   = 1l << 30;
	constexpr int32_t OPERATOR = 1l << 29;
	constexpr int32_t FUNCTION = 1l << 28;

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

		OPERATOR_NEGATE = FUNCTION | 6,	 // Negation
		FUNCTION_SIN	= FUNCTION | 7,	 // Sine
		FUNCTION_COS	= FUNCTION | 8,	 // Cosine
		FUNCTION_TAN	= FUNCTION | 9,	 // Tangent
		FUNCTION_ASIN	= FUNCTION | 10, // Arcsine
		FUNCTION_ACOS	= FUNCTION | 11, // Arccosine
		FUNCTION_ATAN	= FUNCTION | 12, // Arctangent
		FUNCTION_SINH	= FUNCTION | 13, // Hyperbolic Sine
		FUNCTION_COSH	= FUNCTION | 14, // Hyperbolic Cosine
		FUNCTION_TANH	= FUNCTION | 15, // Hyperbolic Tangent
		FUNCTION_ASINH	= FUNCTION | 16, // Hyperbolic Arcsine
		FUNCTION_ACOSH	= FUNCTION | 17, // Hyperbolic Arccosine
		FUNCTION_ATANH	= FUNCTION | 18, // Hyperbolic Arctangent

		FUNCTION_LOG   = FUNCTION | 19, // Log_e
		FUNCTION_LOG2  = FUNCTION | 20, // Log_2
		FUNCTION_LOG10 = FUNCTION | 21, // Log_10
		FUNCTION_EXP   = FUNCTION | 22, // e^x
		FUNCTION_EXP2  = FUNCTION | 23, // 2^x
		FUNCTION_EXP10 = FUNCTION | 24, // 10^x
		FUNCTION_POW   = FUNCTION | 25, // Binary Power (x^y)
		FUNCTION_SQRT  = FUNCTION | 26	// Square Root
	};

	std::string typeToString(const Type &type);
} // namespace symbo
