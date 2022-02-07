/*
 * Error.cpp
 *
 * Contains all the properties any error response from the API will contain. Some properties are optional so might be empty most of the time 
 */

#include "Error.h"

using namespace openapi;

// macro should do the same job. Not really
// OPENAP_JSON_CONVERT_FUNCS(Error, code, message, helpUrl)

void Error::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->code)>(openapi::StringT(OPENAPI_LITERAL(code)), this->code);
    j.AddMember<decltype(this->message)>(openapi::StringT(OPENAPI_LITERAL(message)), this->message);
    j.AddMember<decltype(this->help_url)>(openapi::StringT(OPENAPI_LITERAL(helpUrl)), this->help_url);
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
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(helpUrl))))
    {
        using V = remove_optional<decltype(this->help_url)>::type;
        this->help_url = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(helpUrl)));
    }
}

