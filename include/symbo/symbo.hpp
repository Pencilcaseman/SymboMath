#pragma once

/*
 * Main header file for SymboMath.
 *
 * Defines some useful macros and includes the required headers
 */

// STL includes
#include <string>
#include <cstdint>
#include <stdexcept>
#include <memory>

#ifndef SYMBO_SCALAR
#	define SYMBO_SCALAR double
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
	using Scalar = SYMBO_SCALAR;
}

// SymboMath includes
#include "types.hpp"
#include "component.hpp"
#include "number.hpp"
#include "variable.hpp"
#include "operators/binaryOperator.hpp"
#include "operators/operatorAdd.hpp"
#include "operators/operatorSub.hpp"
#include "operators/operatorMul.hpp"
#include "operators/operatorDiv.hpp"
