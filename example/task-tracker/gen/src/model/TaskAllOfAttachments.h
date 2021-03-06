/*
 * TaskAllOfAttachments.h
 *
 * 
 */

#pragma once


#include <optional>
#include "common_json.h"

namespace openapi {


/*! \brief 
 *
 *  \ingroup Models
 *
 */
struct TaskAllOfAttachments{
    std::optional<openapi::string_t> name;
    std::optional<openapi::string_t> description;
    std::optional<openapi::string_t> url;
    std::optional<openapi::string_t> content_type;
    std::optional<int> size{};
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}