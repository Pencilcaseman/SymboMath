#include <symbo/symbo.hpp>
#include <symbo/types.hpp>

namespace symbo {
	std::string typeToString(const Type &type) {
		switch (type) {
			case Type::TYPE_COMPONENT: return "Component";
			case Type::TYPE_NUMBER: return "Number";
			case Type::TYPE_SYMBOL: return "Variable";
			case Type::TYPE_FUNCTION: return "Function";

			case Type::TOKEN_LPAREN: return "TokenLparen";
			case Type::TOKEN_RPAREN: return "TokenRparen";
			case Type::TOKEN_LSQUARE: return "TokenLsquare";
			case Type::TOKEN_RSQUARE: return "TokenRsquare";
			case Type::TOKEN_LCURLY: return "TokenLcurly";
			case Type::TOKEN_RCURLY: return "TokenRcurly";
			case Type::TOKEN_COLON: return "TokenColon";
			case Type::TOKEN_SEMICOLON: return "TokenSemicolon";
			case Type::TOKEN_POINT: return "TokenPoint";
			case Type::TOKEN_COMMA: return "TokenComma";
			case Type::TOKEN_DQUOTE: return "TokenDquote";
			case Type::TOKEN_SQUOTE: return "TokenSquote";
			case Type::TOKEN_ADD: return "TokenAdd";
			case Type::TOKEN_SUB: return "TokenSub";
			case Type::TOKEN_MUL: return "TokenMul";
			case Type::TOKEN_DIV: return "TokenDiv";
			case Type::TOKEN_MOD: return "TokenMod";
			case Type::TOKEN_EQ: return "TokenEq";
			case Type::TOKEN_LT: return "TokenLt";
			case Type::TOKEN_GT: return "TokenGt";
			case Type::TOKEN_LE: return "TokenLe";
			case Type::TOKEN_GE: return "TokenGe";
			case Type::TOKEN_EXCLAMATION: return "TokenExclamation";

			case Type::OPERATOR_PLUS: return "OperatorPlus";
			case Type::OPERATOR_MINUS: return "OperatorMinus";

			case Type::OPERATOR_ADD: return "OperatorAdd";
			case Type::OPERATOR_SUB: return "OPERATOR_SUB";
			case Type::OPERATOR_MUL: return "OperatorMul";
			case Type::OPERATOR_DIV: return "OperatorDiv";

			case Type::FUNCTION_SIN: return "FunctionSin";
			case Type::FUNCTION_COS: return "FunctionCos";
			case Type::FUNCTION_TAN: return "FunctionTan";
			case Type::FUNCTION_ASIN: return "FunctionAsin";
			case Type::FUNCTION_ACOS: return "FunctionAcos";
			case Type::FUNCTION_ATAN: return "FunctionAtan";
			case Type::FUNCTION_SINH: return "FunctionSinh";
			case Type::FUNCTION_COSH: return "FunctionCosh";
			case Type::FUNCTION_TANH: return "FunctionTanh";
			case Type::FUNCTION_ASINH: return "FunctionAsinh";
			case Type::FUNCTION_ACOSH: return "FunctionAcosh";
			case Type::FUNCTION_ATANH: return "FunctionAtanh";
			case Type::FUNCTION_LOG: return "FunctionLog";
			case Type::FUNCTION_LOG2: return "FunctionLog2";
			case Type::FUNCTION_LOG10: return "FunctionLog10";
			case Type::FUNCTION_EXP: return "FunctionExp";
			case Type::FUNCTION_EXP2: return "FunctionExp2";
			case Type::FUNCTION_EXP10: return "FunctionExp10";
			case Type::FUNCTION_POW: return "FunctionPow";
			case Type::FUNCTION_SQRT: return "FunctionSqrt";
			default: return "Unknown";
		}
	}
} // namespace symbo
