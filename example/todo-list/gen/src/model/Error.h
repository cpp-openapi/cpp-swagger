/*
 * Error.h
 *
 * 
 */

#pragma once


#include <string>
#include <optional>
#include "common_json.h"

namespace openapi {


/*! \brief 
 *
 *  \ingroup Models
 *
 */
struct Error{
    std::optional<int> code{};
    std::optional<openapi::string_t> message;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}