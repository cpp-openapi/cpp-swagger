/*
 * Comment.cpp
 *
 * Users can comment on issues to discuss plans for resolution etc. 
 */

#include "Comment.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(Comment, user, content, createdAt)

void Comment::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->user)>(openapi::StringT(OPENAPI_LITERAL(user)), user);
    j.AddMember<decltype(this->content)>(openapi::StringT(OPENAPI_LITERAL(content)), content);
    j.AddMember<decltype(this->createdAt)>(openapi::StringT(OPENAPI_LITERAL(createdAt)), createdAt);
}

void Comment::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(user))))
    {
        using V = remove_optional<decltype(this->user)>::type;
        this->user = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(user)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(content))))
    {
        using V = remove_optional<decltype(this->content)>::type;
        this->content = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(content)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(createdAt))))
    {
        using V = remove_optional<decltype(this->createdAt)>::type;
        this->createdAt = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(createdAt)));
    }
}

