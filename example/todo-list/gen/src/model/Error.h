/*
 * Error.h
 *
 * 
 */

#pragma once


#include <string>
#include <optional>
#include "model_common.h"
// model.string

namespace openapi {


/*! \brief 
 *
 *  \ingroup Models
 *
 */

struct Error{
    std::optional<int> Code;
    std::optional<openapi::string_t> Message;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}