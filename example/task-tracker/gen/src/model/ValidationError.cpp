/*
 * ValidationError.cpp
 *
 * 
 */

#include "ValidationError.h"

using namespace openapi;

// macro should do the same job. Not really
// OPENAP_JSON_CONVERT_FUNCS(ValidationError, code, message, helpUrl, field)

void ValidationError::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->code)>(openapi::StringT(OPENAPI_LITERAL(code)), this->code);
    j.AddMember<decltype(this->message)>(openapi::StringT(OPENAPI_LITERAL(message)), this->message);
    j.AddMember<decltype(this->help_url)>(openapi::StringT(OPENAPI_LITERAL(helpUrl)), this->help_url);
    j.AddMember<decltype(this->field)>(openapi::StringT(OPENAPI_LITERAL(field)), this->field);
}

void ValidationError::FromJSON(const Json & j)
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
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(field))))
    {
        using V = remove_optional<decltype(this->field)>::type;
        this->field = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(field)));
    }
}

