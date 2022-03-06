#include "TasksApi.h"

using namespace openapi;
// todo include str/json header


// class name TasksApi


void addCommentToTaskParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->id)>::type;
        V idRet;
        bool idOk = req.GetPathParam<V>("id", idRet);
        if(idOk){
            this->id = idRet;
        }
    }
    {
        using V = remove_optional<decltype(this->body)>::type;
        std::string bodyBody = req.GetBody();
        if (bodyBody.size() != 0){
            this->body = Json::Deserialize<V>(openapi::StringT(bodyBody.c_str()));
        }
    }
}

void addCommentToTaskResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
}


void createTaskParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->body)>::type;
        std::string bodyBody = req.GetBody();
        if (bodyBody.size() != 0){
            this->body = Json::Deserialize<V>(openapi::StringT(bodyBody.c_str()));
        }
    }
}

void createTaskResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
}


void deleteTaskParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->id)>::type;
        V idRet;
        bool idOk = req.GetPathParam<V>("id", idRet);
        if(idOk){
            this->id = idRet;
        }
    }
}

void deleteTaskResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
}


void getTaskCommentsParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->id)>::type;
        V idRet;
        bool idOk = req.GetPathParam<V>("id", idRet);
        if(idOk){
            this->id = idRet;
        }
    }
    {
        using V = remove_optional<decltype(this->pageSize)>::type;
        V pageSizeRet;
        bool pageSizeOk = req.GetQueryParam<V>("pageSize", pageSizeRet);
        if(pageSizeOk){
            this->pageSize = pageSizeRet;
        }
    }
    {
        using V = remove_optional<decltype(this->since)>::type;
        V sinceRet;
        bool sinceOk = req.GetQueryParam<V>("since", sinceRet);
        if(sinceOk){
            this->since = sinceRet;
        }
    }
}

void getTaskCommentsResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
    if(this->payload.has_value())
    {
        resp.SetBodyResp(openapi::ToStdString(Json::Serialize(this->payload.value())));
    }
}


void getTaskDetailsParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->id)>::type;
        V idRet;
        bool idOk = req.GetPathParam<V>("id", idRet);
        if(idOk){
            this->id = idRet;
        }
    }
}

void getTaskDetailsResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
    if(this->payload.has_value())
    {
        resp.SetBodyResp(openapi::ToStdString(Json::Serialize(this->payload.value())));
    }
}


void listTasksParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->sinceId)>::type;
        V sinceIdRet;
        bool sinceIdOk = req.GetQueryParam<V>("sinceId", sinceIdRet);
        if(sinceIdOk){
            this->sinceId = sinceIdRet;
        }
    }
    {
        using V = remove_optional<decltype(this->tags)>::type;
        V tagsRet;
        bool tagsOk = req.GetQueryParam<V>("tags", tagsRet);
        if(tagsOk){
            this->tags = tagsRet;
        }
    }
    {
        using V = remove_optional<decltype(this->status)>::type;
        V statusRet;
        bool statusOk = req.GetQueryParam<V>("status", statusRet);
        if(statusOk){
            this->status = statusRet;
        }
    }
    {
        using V = remove_optional<decltype(this->pageSize)>::type;
        V pageSizeRet;
        bool pageSizeOk = req.GetQueryParam<V>("pageSize", pageSizeRet);
        if(pageSizeOk){
            this->pageSize = pageSizeRet;
        }
    }
}

void listTasksResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
    if(this->payload.has_value())
    {
        resp.SetBodyResp(openapi::ToStdString(Json::Serialize(this->payload.value())));
    }
}


void updateTaskParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->id)>::type;
        V idRet;
        bool idOk = req.GetPathParam<V>("id", idRet);
        if(idOk){
            this->id = idRet;
        }
    }
    {
        using V = remove_optional<decltype(this->body)>::type;
        std::string bodyBody = req.GetBody();
        if (bodyBody.size() != 0){
            this->body = Json::Deserialize<V>(openapi::StringT(bodyBody.c_str()));
        }
    }
}

void updateTaskResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
    if(this->payload.has_value())
    {
        resp.SetBodyResp(openapi::ToStdString(Json::Serialize(this->payload.value())));
    }
}


void uploadTaskFileParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->id)>::type;
        V idRet;
        bool idOk = req.GetPathParam<V>("id", idRet);
        if(idOk){
            this->id = idRet;
        }
    }
    {
        using V = remove_optional<decltype(this->file)>::type;
    }
    {
        using V = remove_optional<decltype(this->description)>::type;
    }
}

void uploadTaskFileResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
}


