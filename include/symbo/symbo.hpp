#pragma once

/*
 * Main header file for SymboMath.
 *
 * Defines some useful macros and includes the required headers
 */

// STL includes
#include <string>
#include <vector>
#include <memory>
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iostream> // TODO: Remove when no longer required

#ifndef SYMBO_MAX_PRINT_DEPTH
#	define SYMBO_MAX_PRINT_DEPTH 100
#endif

#ifndef SYMBO_SCALAR
#	define SYMBO_SCALAR double
#endif

#ifndef SYMBO_INTEGER
#	define SYMBO_INTEGER int64_t
#endif

#ifndef SYMBO_MATH_LIB
#	define SYMBO_MATH_LIB ::std
#endif

#ifndef SYMBO_TO_STRING
#	define SYMBO_TO_STRING std::to_string
#endif

#define STRINGIFY(a) STR_IMPL_(a)
#define STR_IMPL_(a) #a

namespace symbo {
	using Real = SYMBO_SCALAR;
	using Int  = SYMBO_INTEGER;
} // namespace symbo

// SymboMath includes
#include "error.hpp"
#include "types.hpp"
#include "respectTo.hpp"
#include "component.hpp"
#include "number.hpp"
#include "variable.hpp"
#include "function.hpp"

#include "operators/binaryOperator.hpp"
#include "operators/operatorAdd.hpp"
#include "operators/operatorSub.hpp"
#include "operators/operatorMul.hpp"
#include "operators/operatorDiv.hpp"

#include "operators/unaryOperator.hpp"
#include "operators/operatorNegate.hpp"
#include "operators/operatorSin.hpp"
#include "operators/operatorCos.hpp"
#include "operators/operatorTan.hpp"
#include "operators/operatorAsin.hpp"
#include "operators/operatorAcos.hpp"
#include "operators/operatorAtan.hpp"
#include "operators/operatorSinh.hpp"
#include "operators/operatorCosh.hpp"
#include "operators/operatorTanh.hpp"
#include "operators/operatorAsinh.hpp"
#include "operators/operatorAcosh.hpp"
#include "operators/operatorAtanh.hpp"
#include "operators/operatorLog.hpp"
#include "operators/operatorLog2.hpp"
#include "operators/operatorLog10.hpp"
#include "operators/operatorExp.hpp"
#include "operators/operatorPow.hpp"
#include "operators/operatorSqrt.hpp"

#include "lexer.hpp"
#include "parser.hpp"
