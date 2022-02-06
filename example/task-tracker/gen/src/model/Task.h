/*
 * Task.h
 *
 * A Task is the main entity in this application. Everything revolves around tasks and managing them. 
 */

#pragma once


#include <string>
#include <optional>
#include "common_json.h"
#include "Comment.h"
#include "Milestone.h"
#include "TaskAllOf.h"
#include "TaskAllOfAttachments.h"
#include "TaskCard.h"
#include "UserCard.h"
#include <vector>

namespace openapi {


/*! \brief A Task is the main entity in this application. Everything revolves around tasks and managing them. 
 *
 *  \ingroup Models
 *
 */
struct Task{
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
    std::optional<openapi::string_t> last_updated;
    std::optional<UserCard> reported_by;
    std::optional<UserCard> last_updated_by;
    // array
    std::vector<Comment> comments;
    // additional properties should be rendered as json. string for now.
    openapi::string_t attachments;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}