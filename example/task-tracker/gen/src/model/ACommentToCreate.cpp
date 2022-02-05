/*
 * ACommentToCreate.cpp
 *
 * These values can have github flavored markdown. 
 */

#include "ACommentToCreate.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(ACommentToCreate, userId, content)

void ACommentToCreate::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->user_id)>(openapi::StringT(OPENAPI_LITERAL(userId)), this->user_id);
    j.AddMember<decltype(this->content)>(openapi::StringT(OPENAPI_LITERAL(content)), this->content);
}

void ACommentToCreate::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(userId))))
    {
        using V = remove_optional<decltype(this->user_id)>::type;
        this->user_id = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(userId)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(content))))
    {
        using V = remove_optional<decltype(this->content)>::type;
        this->content = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(content)));
    }
}

