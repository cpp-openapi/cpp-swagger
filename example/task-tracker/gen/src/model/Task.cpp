/*
 * Task.cpp
 *
 * A Task is the main entity in this application. Everything revolves around tasks and managing them. 
 */

#include "Task.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(Task, id, title, description, milestone, severity, effort, karma, status, assignedTo, reportedAt, tags, lastUpdated, reportedBy, lastUpdatedBy, comments, attachments)

void Task::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->id)>(openapi::StringT(OPENAPI_LITERAL(id)), id);
    j.AddMember<decltype(this->title)>(openapi::StringT(OPENAPI_LITERAL(title)), title);
    j.AddMember<decltype(this->description)>(openapi::StringT(OPENAPI_LITERAL(description)), description);
    j.AddMember<decltype(this->milestone)>(openapi::StringT(OPENAPI_LITERAL(milestone)), milestone);
    j.AddMember<decltype(this->severity)>(openapi::StringT(OPENAPI_LITERAL(severity)), severity);
    j.AddMember<decltype(this->effort)>(openapi::StringT(OPENAPI_LITERAL(effort)), effort);
    j.AddMember<decltype(this->karma)>(openapi::StringT(OPENAPI_LITERAL(karma)), karma);
    j.AddMember<decltype(this->status)>(openapi::StringT(OPENAPI_LITERAL(status)), status);
    j.AddMember<decltype(this->assignedTo)>(openapi::StringT(OPENAPI_LITERAL(assignedTo)), assignedTo);
    j.AddMember<decltype(this->reportedAt)>(openapi::StringT(OPENAPI_LITERAL(reportedAt)), reportedAt);
    j.AddMember<decltype(this->tags)>(openapi::StringT(OPENAPI_LITERAL(tags)), tags);
    j.AddMember<decltype(this->lastUpdated)>(openapi::StringT(OPENAPI_LITERAL(lastUpdated)), lastUpdated);
    j.AddMember<decltype(this->reportedBy)>(openapi::StringT(OPENAPI_LITERAL(reportedBy)), reportedBy);
    j.AddMember<decltype(this->lastUpdatedBy)>(openapi::StringT(OPENAPI_LITERAL(lastUpdatedBy)), lastUpdatedBy);
    j.AddMember<decltype(this->comments)>(openapi::StringT(OPENAPI_LITERAL(comments)), comments);
    j.AddMember<decltype(this->attachments)>(openapi::StringT(OPENAPI_LITERAL(attachments)), attachments);
}

void Task::FromJSON(const Json & j)
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
        using V = remove_optional<decltype(this->assignedTo)>::type;
        this->assignedTo = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(assignedTo)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(reportedAt))))
    {
        using V = remove_optional<decltype(this->reportedAt)>::type;
        this->reportedAt = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(reportedAt)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(tags))))
    {
        using V = remove_optional<decltype(this->tags)>::type;
        this->tags = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(tags)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(lastUpdated))))
    {
        using V = remove_optional<decltype(this->lastUpdated)>::type;
        this->lastUpdated = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(lastUpdated)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(reportedBy))))
    {
        using V = remove_optional<decltype(this->reportedBy)>::type;
        this->reportedBy = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(reportedBy)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(lastUpdatedBy))))
    {
        using V = remove_optional<decltype(this->lastUpdatedBy)>::type;
        this->lastUpdatedBy = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(lastUpdatedBy)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(comments))))
    {
        using V = remove_optional<decltype(this->comments)>::type;
        this->comments = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(comments)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(attachments))))
    {
        using V = remove_optional<decltype(this->attachments)>::type;
        this->attachments = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(attachments)));
    }
}

