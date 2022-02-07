/*
 * ValidationErrorAllOf.cpp
 *
 * 
 */

#include "ValidationErrorAllOf.h"

using namespace openapi;

// macro should do the same job. Not really
// OPENAP_JSON_CONVERT_FUNCS(ValidationErrorAllOf, field)

void ValidationErrorAllOf::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->field)>(openapi::StringT(OPENAPI_LITERAL(field)), this->field);
}

void ValidationErrorAllOf::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(field))))
    {
        using V = remove_optional<decltype(this->field)>::type;
        this->field = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(field)));
    }
}

