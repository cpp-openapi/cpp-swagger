/*
 * TaskCard.h
 *
 * A task card is a minimalistic representation of a task. Useful for display in list views, like a card list. 
 */

#pragma once


#include <optional>
#include "common_json.h"
#include "Milestone.h"
#include "UserCard.h"
#include <vector>

namespace openapi {


/*! \brief A task card is a minimalistic representation of a task. Useful for display in list views, like a card list. 
 *
 *  \ingroup Models
 *
 */
struct TaskCard{
    std::optional<int> id{};
    std::optional<openapi::string_t> title;
    std::optional<openapi::string_t> description;
    std::optional<Milestone> milestone;
    std::optional<int> severity{};
    std::optional<int> effort{};
    std::optional<int> karma{};
    std::optional<openapi::string_t> status;
    std::optional<UserCard> assigned_to;
    std::optional<openapi::string_t> reported_at;
    // array
    std::vector<openapi::string_t> tags;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}