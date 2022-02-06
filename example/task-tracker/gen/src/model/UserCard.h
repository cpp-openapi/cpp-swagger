/*
 * UserCard.h
 *
 * This representation of a user is mainly meant for inclusion in other models, or for list views. 
 */

#pragma once


#include <string>
#include <optional>
#include "common_json.h"

namespace openapi {


/*! \brief This representation of a user is mainly meant for inclusion in other models, or for list views. 
 *
 *  \ingroup Models
 *
 */
struct UserCard{
    std::optional<int> id{};
    std::optional<openapi::string_t> screen_name;
    std::optional<int> available_karma{};
    std::optional<bool> admin{};
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}