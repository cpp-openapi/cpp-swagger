/*
 * Milestone.h
 *
 * Milestones can have a escription and due date. This can be useful for filters and such. 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"
#include "SomeCountersForThisMilestone.h"

namespace openapi {


/*! \brief Milestones can have a escription and due date. This can be useful for filters and such. 
 *
 *  \ingroup Models
 *
 */
struct Milestone{
    std::optional<openapi::string_t> name;
    std::optional<openapi::string_t> description;
    std::optional<openapi::string_t> due_date;
    std::optional<SomeCountersForThisMilestone> stats;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}