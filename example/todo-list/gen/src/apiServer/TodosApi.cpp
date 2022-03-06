#include "TodosApi.h"

using namespace openapi;
// todo include str/json header


// class name TodosApi


void addOneParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->body)>::type;
        std::string bodyBody = req.GetBody();
        if (bodyBody.size() != 0){
            this->body = Json::Deserialize<V>(openapi::StringT(bodyBody.c_str()));
        }
    }
}

void addOneResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
    if(this->payload.has_value())
    {
        resp.SetBodyResp(openapi::ToStdString(Json::Serialize(this->payload.value())));
    }
}


void destroyOneParams::ReadParams(IOASClientRequest & req)
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

void destroyOneResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
}


void findTodosParams::ReadParams(IOASClientRequest & req)
{
    {
        using V = remove_optional<decltype(this->since)>::type;
        V sinceRet;
        bool sinceOk = req.GetQueryParam<V>("since", sinceRet);
        if(sinceOk){
            this->since = sinceRet;
        }
    }
    {
        using V = remove_optional<decltype(this->limit)>::type;
        V limitRet;
        bool limitOk = req.GetQueryParam<V>("limit", limitRet);
        if(limitOk){
            this->limit = limitRet;
        }
    }
}

void findTodosResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
    if(this->payload.has_value())
    {
        resp.SetBodyResp(openapi::ToStdString(Json::Serialize(this->payload.value())));
    }
}


void updateOneParams::ReadParams(IOASClientRequest & req)
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

void updateOneResponse::WriteResponse(IOASClientResponse & resp)
{
    resp.SetCode(this->code);
    if(this->payload.has_value())
    {
        resp.SetBodyResp(openapi::ToStdString(Json::Serialize(this->payload.value())));
    }
}


