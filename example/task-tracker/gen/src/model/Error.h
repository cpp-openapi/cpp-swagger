/*
 * Error.h
 *
 * Contains all the properties any error response from the API will contain. Some properties are optional so might be empty most of the time 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"

namespace openapi {


/*! \brief Contains all the properties any error response from the API will contain. Some properties are optional so might be empty most of the time 
 *
 *  \ingroup Models
 *
 */

struct Error{
    std::optional<int> code{};
    std::optional<openapi::string_t> message;
    std::optional<openapi::string_t> helpUrl;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}