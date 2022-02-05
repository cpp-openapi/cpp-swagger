/*
 * TaskCard.cpp
 *
 * A task card is a minimalistic representation of a task. Useful for display in list views, like a card list. 
 */

#include "TaskCard.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(TaskCard, id, title, description, milestone, severity, effort, karma, status, assignedTo, reportedAt, tags)

void TaskCard::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->id)>(openapi::StringT(OPENAPI_LITERAL(id)), this->id);
    j.AddMember<decltype(this->title)>(openapi::StringT(OPENAPI_LITERAL(title)), this->title);
    j.AddMember<decltype(this->description)>(openapi::StringT(OPENAPI_LITERAL(description)), this->description);
    j.AddMember<decltype(this->milestone)>(openapi::StringT(OPENAPI_LITERAL(milestone)), this->milestone);
    j.AddMember<decltype(this->severity)>(openapi::StringT(OPENAPI_LITERAL(severity)), this->severity);
    j.AddMember<decltype(this->effort)>(openapi::StringT(OPENAPI_LITERAL(effort)), this->effort);
    j.AddMember<decltype(this->karma)>(openapi::StringT(OPENAPI_LITERAL(karma)), this->karma);
    j.AddMember<decltype(this->status)>(openapi::StringT(OPENAPI_LITERAL(status)), this->status);
    j.AddMember<decltype(this->assigned_to)>(openapi::StringT(OPENAPI_LITERAL(assignedTo)), this->assigned_to);
    j.AddMember<decltype(this->reported_at)>(openapi::StringT(OPENAPI_LITERAL(reportedAt)), this->reported_at);
    j.AddMember<decltype(this->tags)>(openapi::StringT(OPENAPI_LITERAL(tags)), this->tags);
}

void TaskCard::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(id))))
    {
        using V = remove_optional<decltype(this->id)>::type;
        this->id = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(id)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(title))))
    {
        using V = remove_optional<decltype(this->title)>::type;
        this->title = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(title)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(description))))
    {
        using V = remove_optional<decltype(this->description)>::type;
        this->description = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(description)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(milestone))))
    {
        using V = remove_optional<decltype(this->milestone)>::type;
        this->milestone = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(milestone)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(severity))))
    {
        using V = remove_optional<decltype(this->severity)>::type;
        this->severity = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(severity)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(effort))))
    {
        using V = remove_optional<decltype(this->effort)>::type;
        this->effort = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(effort)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(karma))))
    {
        using V = remove_optional<decltype(this->karma)>::type;
        this->karma = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(karma)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(status))))
    {
        using V = remove_optional<decltype(this->status)>::type;
        this->status = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(status)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(assignedTo))))
    {
        using V = remove_optional<decltype(this->assigned_to)>::type;
        this->assigned_to = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(assignedTo)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(reportedAt))))
    {
        using V = remove_optional<decltype(this->reported_at)>::type;
        this->reported_at = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(reportedAt)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(tags))))
    {
        using V = remove_optional<decltype(this->tags)>::type;
        this->tags = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(tags)));
    }
}

