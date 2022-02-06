/*
 * Comment.h
 *
 * Users can comment on issues to discuss plans for resolution etc. 
 */

#pragma once


#include <string>
#include <optional>
#include "common_json.h"
#include "UserCard.h"

namespace openapi {


/*! \brief Users can comment on issues to discuss plans for resolution etc. 
 *
 *  \ingroup Models
 *
 */
struct Comment{
    std::optional<UserCard> user;
    std::optional<openapi::string_t> content;
    std::optional<openapi::string_t> created_at;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}