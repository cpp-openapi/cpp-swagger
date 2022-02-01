/*
 * Item.h
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

struct Item{
    std::optional<int> Id;
    std::optional<openapi::string_t> Description;
    std::optional<bool> Completed;
    OPENAPI_JSON_CONVERT_FUNCS_DECLARE
};
}