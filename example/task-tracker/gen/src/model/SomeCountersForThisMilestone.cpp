/*
 * SomeCountersForThisMilestone.cpp
 *
 * This object contains counts for the remaining open issues and the amount of issues that have been closed. 
 */

#include "SomeCountersForThisMilestone.h"

using namespace openapi;

// macro should do the same job. Not really
// OPENAP_JSON_CONVERT_FUNCS(SomeCountersForThisMilestone, open, closed, total)

void SomeCountersForThisMilestone::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->open)>(openapi::StringT(OPENAPI_LITERAL(open)), this->open);
    j.AddMember<decltype(this->closed)>(openapi::StringT(OPENAPI_LITERAL(closed)), this->closed);
    j.AddMember<decltype(this->total)>(openapi::StringT(OPENAPI_LITERAL(total)), this->total);
}

void SomeCountersForThisMilestone::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(open))))
    {
        using V = remove_optional<decltype(this->open)>::type;
        this->open = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(open)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(closed))))
    {
        using V = remove_optional<decltype(this->closed)>::type;
        this->closed = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(closed)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(total))))
    {
        using V = remove_optional<decltype(this->total)>::type;
        this->total = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(total)));
    }
}

