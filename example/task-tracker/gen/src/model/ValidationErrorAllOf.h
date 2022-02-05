/*
 * ValidationErrorAllOf.h
 *
 * 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"

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