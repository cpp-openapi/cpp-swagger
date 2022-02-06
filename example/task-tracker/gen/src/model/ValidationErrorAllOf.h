/*
 * ValidationErrorAllOf.h
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
struct ValidationErrorAllOf{
    std::optional<openapi::string_t> field;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}