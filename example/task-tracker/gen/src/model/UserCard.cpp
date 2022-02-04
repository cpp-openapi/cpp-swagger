/*
 * UserCard.cpp
 *
 * This representation of a user is mainly meant for inclusion in other models, or for list views. 
 */

#include "UserCard.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(UserCard, id, screenName, availableKarma, admin)

void UserCard::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->id)>(openapi::StringT(OPENAPI_LITERAL(id)), id);
    j.AddMember<decltype(this->screenName)>(openapi::StringT(OPENAPI_LITERAL(screenName)), screenName);
    j.AddMember<decltype(this->availableKarma)>(openapi::StringT(OPENAPI_LITERAL(availableKarma)), availableKarma);
    j.AddMember<decltype(this->admin)>(openapi::StringT(OPENAPI_LITERAL(admin)), admin);
}

void UserCard::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(id))))
    {
        using V = remove_optional<decltype(this->id)>::type;
        this->id = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(id)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(screenName))))
    {
        using V = remove_optional<decltype(this->screenName)>::type;
        this->screenName = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(screenName)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(availableKarma))))
    {
        using V = remove_optional<decltype(this->availableKarma)>::type;
        this->availableKarma = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(availableKarma)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(admin))))
    {
        using V = remove_optional<decltype(this->admin)>::type;
        this->admin = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(admin)));
    }
}

