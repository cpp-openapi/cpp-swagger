/*
 * Milestone.cpp
 *
 * Milestones can have a escription and due date. This can be useful for filters and such. 
 */

#include "Milestone.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(Milestone, name, description, dueDate, stats)

void Milestone::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->name)>(openapi::StringT(OPENAPI_LITERAL(name)), name);
    j.AddMember<decltype(this->description)>(openapi::StringT(OPENAPI_LITERAL(description)), description);
    j.AddMember<decltype(this->dueDate)>(openapi::StringT(OPENAPI_LITERAL(dueDate)), dueDate);
    j.AddMember<decltype(this->stats)>(openapi::StringT(OPENAPI_LITERAL(stats)), stats);
}

void Milestone::FromJSON(const Json & j)
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
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(dueDate))))
    {
        using V = remove_optional<decltype(this->dueDate)>::type;
        this->dueDate = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(dueDate)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(stats))))
    {
        using V = remove_optional<decltype(this->stats)>::type;
        this->stats = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(stats)));
    }
}

