/*
 * Error.cpp
 *
 * 
 */

#include "Error.h"

using namespace openapi;

// macro should do the same job. Not really
// OPENAP_JSON_CONVERT_FUNCS(Error, code, message)

void Error::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->code)>(openapi::StringT(OPENAPI_LITERAL(code)), this->code);
    j.AddMember<decltype(this->message)>(openapi::StringT(OPENAPI_LITERAL(message)), this->message);
}

void Error::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(code))))
    {
        using V = remove_optional<decltype(this->code)>::type;
        this->code = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(code)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(message))))
    {
        using V = remove_optional<decltype(this->message)>::type;
        this->message = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(message)));
    }
}

