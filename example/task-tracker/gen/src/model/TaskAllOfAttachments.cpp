/*
 * TaskAllOfAttachments.cpp
 *
 * 
 */

#include "TaskAllOfAttachments.h"

using namespace openapi;

// macro should do the same job. Not really
// OPENAP_JSON_CONVERT_FUNCS(TaskAllOfAttachments, name, description, url, contentType, size)

void TaskAllOfAttachments::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->name)>(openapi::StringT(OPENAPI_LITERAL(name)), this->name);
    j.AddMember<decltype(this->description)>(openapi::StringT(OPENAPI_LITERAL(description)), this->description);
    j.AddMember<decltype(this->url)>(openapi::StringT(OPENAPI_LITERAL(url)), this->url);
    j.AddMember<decltype(this->content_type)>(openapi::StringT(OPENAPI_LITERAL(contentType)), this->content_type);
    j.AddMember<decltype(this->size)>(openapi::StringT(OPENAPI_LITERAL(size)), this->size);
}

void TaskAllOfAttachments::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(name))))
    {
        using V = remove_optional<decltype(this->name)>::type;
        this->name = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(name)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(description))))
    {
        using V = remove_optional<decltype(this->description)>::type;
        this->description = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(description)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(url))))
    {
        using V = remove_optional<decltype(this->url)>::type;
        this->url = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(url)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(contentType))))
    {
        using V = remove_optional<decltype(this->content_type)>::type;
        this->content_type = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(contentType)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(size))))
    {
        using V = remove_optional<decltype(this->size)>::type;
        this->size = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(size)));
    }
}

