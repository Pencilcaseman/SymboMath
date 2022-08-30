#include <symbo/symbo.hpp>
#include <symbo/types.hpp>

namespace symbo {
	std::string typeToString(const Type &type) {
		switch (type) {
			case Type::COMPONENT: return "Component";
			case Type::NUMBER: return "Number";
			case Type::VARIABLE: return "Variable";
			case Type::FUNCTION: return "Function";
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
