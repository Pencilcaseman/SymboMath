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
			case Type::OPERATOR_SIN: return "OperatorSin";
			case Type::OPERATOR_COS: return "OperatorCos";
			case Type::OPERATOR_TAN: return "OperatorTan";
			case Type::OPERATOR_ASIN: return "OperatorAsin";
			case Type::OPERATOR_ACOS: return "OperatorAcos";
			case Type::OPERATOR_ATAN: return "OperatorAtan";
			case Type::OPERATOR_SINH: return "OperatorSinh";
			case Type::OPERATOR_COSH: return "OperatorCosh";
			case Type::OPERATOR_TANH: return "OperatorTanh";
			case Type::OPERATOR_ASINH: return "OperatorAsinh";
			case Type::OPERATOR_ACOSH: return "OperatorAcosh";
			case Type::OPERATOR_ATANH: return "OperatorAtanh";
			case Type::OPERATOR_LOG: return "OperatorLog";
			case Type::OPERATOR_LOG2: return "OperatorLog2";
			case Type::OPERATOR_LOG10: return "OperatorLog10";
			case Type::OPERATOR_EXP: return "OperatorExp";
			case Type::OPERATOR_EXP2: return "OperatorExp2";
			case Type::OPERATOR_EXP10: return "OperatorExp10";
			case Type::OPERATOR_POW: return "OperatorPow";
			case Type::OPERATOR_SQRT: return "OperatorSqrt";
			default: return "Unknown";
		}
	}
} // namespace symbo
