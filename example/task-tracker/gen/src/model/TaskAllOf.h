/*
 * TaskAllOf.h
 *
 * 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"
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
    std::optional<openapi::string_t> lastUpdated;
    std::optional<UserCard> reportedBy;
    std::optional<UserCard> lastUpdatedBy;
    // array
    std::vector<Comment> comments;
    // additional properties should be rendered as json. string for now.
    openapi::string_t attachments;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}