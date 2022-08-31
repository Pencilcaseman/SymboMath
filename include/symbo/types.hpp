#pragma once

namespace symbo {
	enum class Type {
		TYPE_COMPONENT, // Base class for all types
		TYPE_NUMBER,	// A scalar
		TYPE_SYMBOL,	// A symbol (variable)
		TYPE_FUNCTION,	// A user-defined function

		TOKEN_LPAREN,	   // (
		TOKEN_RPAREN,	   // )
		TOKEN_LSQUARE,	   // [
		TOKEN_RSQUARE,	   // ]
		TOKEN_LCURLY,	   // {
		TOKEN_RCURLY,	   // }
		TOKEN_COLON,	   // :
		TOKEN_SEMICOLON,   // ;
		TOKEN_POINT,	   // .
		TOKEN_COMMA,	   // ,
		TOKEN_DQUOTE,	   // "
		TOKEN_SQUOTE,	   // '
		TOKEN_ADD,		   // +
		TOKEN_SUB,		   // -
		TOKEN_MUL,		   // *
		TOKEN_DIV,		   // /
		TOKEN_MOD,		   // %
		TOKEN_EQ,		   // ==
		TOKEN_LT,		   // <
		TOKEN_GT,		   // >
		TOKEN_LE,		   // <=
		TOKEN_GE,		   // >=
		TOKEN_EXCLAMATION, // !

		OPERATOR_PLUS,	// Unary plus
		OPERATOR_MINUS, // Unary minus

		OPERATOR_ADD, // Binary Addition
		OPERATOR_SUB, // Binary Subtraction
		OPERATOR_MUL, // Binary Multiplication
		OPERATOR_DIV, // Binary Division

		OPERATOR_SIN,	// Sine
		OPERATOR_COS,	// Cosine
		OPERATOR_TAN,	// Tangent
		OPERATOR_ASIN,	// Arcsine
		OPERATOR_ACOS,	// Arccosine
		OPERATOR_ATAN,	// Arctangent
		OPERATOR_SINH,	// Hyperbolic Sine
		OPERATOR_COSH,	// Hyperbolic Cosine
		OPERATOR_TANH,	// Hyperbolic Tangent
		OPERATOR_ASINH, // Hyperbolic Arcsine
		OPERATOR_ACOSH, // Hyperbolic Arccosine
		OPERATOR_ATANH, // Hyperbolic Arctangent

		OPERATOR_LOG,	// Log_e
		OPERATOR_LOG2,	// Log_10
		OPERATOR_LOG10, // Log_10
		OPERATOR_EXP,	// e^x
		OPERATOR_EXP2,	// 2^x
		OPERATOR_EXP10, // 10^x
		OPERATOR_POW,	// Binary Power (x^y)
		OPERATOR_SQRT	// Square Root
	};

	std::string typeToString(const Type &type);
} // namespace symbo
