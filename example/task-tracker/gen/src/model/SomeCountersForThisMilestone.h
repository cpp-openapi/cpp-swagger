/*
 * SomeCountersForThisMilestone.h
 *
 * This object contains counts for the remaining open issues and the amount of issues that have been closed. 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"

namespace openapi {


/*! \brief This object contains counts for the remaining open issues and the amount of issues that have been closed. 
 *
 *  \ingroup Models
 *
 */
struct SomeCountersForThisMilestone{
    std::optional<int> open{};
    std::optional<int> closed{};
    std::optional<int> total{};
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}