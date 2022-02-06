/*
 * TaskAllOf.h
 *
 * 
 */

#pragma once


#include <string>
#include <optional>
#include "common_json.h"
#include "Comment.h"
#include "TaskAllOfAttachments.h"
#include "UserCard.h"
#include <vector>

namespace openapi {


/*! \brief 
 *
 *  \ingroup Models
 *
 */
struct TaskAllOf{
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