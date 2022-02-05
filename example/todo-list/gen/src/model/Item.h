/*
 * Item.h
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
struct Item{
    std::optional<int> id{};
    std::optional<openapi::string_t> description;
    std::optional<bool> completed{};
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}