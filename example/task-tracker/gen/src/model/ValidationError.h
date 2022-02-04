/*
 * ValidationError.h
 *
 * 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"
#include "Error.h"
#include "ValidationErrorAllOf.h"

namespace openapi {


/*! \brief 
 *
 *  \ingroup Models
 *
 */

struct ValidationError{
    std::optional<int> code{};
    std::optional<openapi::string_t> message;
    std::optional<openapi::string_t> helpUrl;
    std::optional<openapi::string_t> field;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}