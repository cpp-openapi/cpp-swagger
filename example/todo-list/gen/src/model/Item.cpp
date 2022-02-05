/*
 * Item.cpp
 *
 * 
 */

#include "Item.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(Item, id, description, completed)

void Item::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->id)>(openapi::StringT(OPENAPI_LITERAL(id)), this->id);
    j.AddMember<decltype(this->description)>(openapi::StringT(OPENAPI_LITERAL(description)), this->description);
    j.AddMember<decltype(this->completed)>(openapi::StringT(OPENAPI_LITERAL(completed)), this->completed);
}

void Item::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(id))))
    {
        using V = remove_optional<decltype(this->id)>::type;
        this->id = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(id)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(description))))
    {
        using V = remove_optional<decltype(this->description)>::type;
        this->description = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(description)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(completed))))
    {
        using V = remove_optional<decltype(this->completed)>::type;
        this->completed = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(completed)));
    }
}

