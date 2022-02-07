/*
 * Item.h
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
struct Item{
    std::optional<int> id{};
    std::optional<openapi::string_t> description;
    std::optional<bool> completed{};
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}