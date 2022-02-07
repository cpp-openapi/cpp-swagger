/*
 * ACommentToCreate.h
 *
 * These values can have github flavored markdown. 
 */

#pragma once


#include <optional>
#include "common_json.h"

namespace openapi {


/*! \brief These values can have github flavored markdown. 
 *
 *  \ingroup Models
 *
 */
struct ACommentToCreate{
    std::optional<int> user_id{};
    std::optional<openapi::string_t> content;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}