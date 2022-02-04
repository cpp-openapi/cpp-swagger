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
    j.AddMember<decltype(this->lastUpdated)>(openapi::StringT(OPENAPI_LITERAL(lastUpdated)), lastUpdated);
    j.AddMember<decltype(this->reportedBy)>(openapi::StringT(OPENAPI_LITERAL(reportedBy)), reportedBy);
    j.AddMember<decltype(this->lastUpdatedBy)>(openapi::StringT(OPENAPI_LITERAL(lastUpdatedBy)), lastUpdatedBy);
    j.AddMember<decltype(this->comments)>(openapi::StringT(OPENAPI_LITERAL(comments)), comments);
    j.AddMember<decltype(this->attachments)>(openapi::StringT(OPENAPI_LITERAL(attachments)), attachments);
}

void TaskAllOf::FromJSON(const Json & j)
{
    // OPENAPI_FOR_EACH(OPENAPI_FROM_JSON_MEMBER, __VA_ARGS__)
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

