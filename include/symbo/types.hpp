#pragma once

namespace symbo {
	enum class Type {
		COMPONENT, // Base class for all types
		NUMBER,	   // A scalar
		VARIABLE,  // A symbol (variable)
		FUNCTION,  // A user-defined function

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
		OPERATOR_EXP10,	// 10^x
		OPERATOR_POW,	// Binary Power (x^y)
		OPERATOR_SQRT	// Square Root
	};

	std::string typeToString(const Type &type);
} // namespace symbo
