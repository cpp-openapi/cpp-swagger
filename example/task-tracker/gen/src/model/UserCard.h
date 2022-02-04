/*
 * UserCard.h
 *
 * This representation of a user is mainly meant for inclusion in other models, or for list views. 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"

namespace openapi {


/*! \brief This representation of a user is mainly meant for inclusion in other models, or for list views. 
 *
 *  \ingroup Models
 *
 */

struct UserCard{
    std::optional<int> id{};
    std::optional<openapi::string_t> screenName;
    std::optional<int> availableKarma{};
    std::optional<bool> admin{};
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}