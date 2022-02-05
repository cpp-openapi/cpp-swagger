/*
 * TaskAllOf.cpp
 *
 * 
 */

#include "TaskAllOf.h"

using namespace openapi;

// macro should do the same job
// OPENAP_JSON_CONVERT_FUNCS(TaskAllOf, lastUpdated, reportedBy, lastUpdatedBy, comments, attachments)

void TaskAllOf::ToJSON(Json & j) const
{
    // OPENAPI_FOR_EACH(OPENAPI_TO_JSON_MEMBER, __VA_ARGS__)
    j.AddMember<decltype(this->last_updated)>(openapi::StringT(OPENAPI_LITERAL(lastUpdated)), this->last_updated);
    j.AddMember<decltype(this->reported_by)>(openapi::StringT(OPENAPI_LITERAL(reportedBy)), this->reported_by);
    j.AddMember<decltype(this->last_updated_by)>(openapi::StringT(OPENAPI_LITERAL(lastUpdatedBy)), this->last_updated_by);
    j.AddMember<decltype(this->comments)>(openapi::StringT(OPENAPI_LITERAL(comments)), this->comments);
    j.AddMember<decltype(this->attachments)>(openapi::StringT(OPENAPI_LITERAL(attachments)), this->attachments);
}

void TaskAllOf::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(lastUpdated))))
    {
        using V = remove_optional<decltype(this->last_updated)>::type;
        this->last_updated = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(lastUpdated)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(reportedBy))))
    {
        using V = remove_optional<decltype(this->reported_by)>::type;
        this->reported_by = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(reportedBy)));
    }
    if(j.HasKey(openapi::StringT(OPENAPI_LITERAL(lastUpdatedBy))))
    {
        using V = remove_optional<decltype(this->last_updated_by)>::type;
        this->last_updated_by = j.GetMember<V>(openapi::StringT(OPENAPI_LITERAL(lastUpdatedBy)));
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

