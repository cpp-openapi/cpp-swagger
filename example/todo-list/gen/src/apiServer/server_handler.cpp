#include "server_handler.h"

using namespace openapi;

Server::Server(std::shared_ptr<ServerHandler> handler): handler_(handler), router_({})
{
    RouteBuilder<std::function<void(IOASClientRequest &, IOASClientResponse &)>> b;

    // std::function<void(IOASClientRequest & req, IOASClientResponse &resp)>
    b.AddRoute("POST", "/",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            addOneParams params;
            params.ReadParams(req);
            addOneResponse res = this->handler_->addOneHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("DELETE", "/{id}",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            destroyOneParams params;
            params.ReadParams(req);
            destroyOneResponse res = this->handler_->destroyOneHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("GET", "/",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            findTodosParams params;
            params.ReadParams(req);
            findTodosResponse res = this->handler_->findTodosHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("PUT", "/{id}",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            updateOneParams params;
            params.ReadParams(req);
            updateOneResponse res = this->handler_->updateOneHandleFunc(params);
            res.WriteResponse(resp);
        });

    this->router_ = b.Build();
}

bool Server::GetHandlerFunc(std::string const & method, std::string const & path, PathParamValue &paramsRet, std::function<void(IOASClientRequest &, IOASClientResponse &)> & ret)
{
    bool ok = this->router_.LookUp(method, path, paramsRet, ret);
    return ok;
}



addOneResponse ServerHandler::addOneHandleFunc(addOneParams params)
{
    // not implemented
    return addOneResponse{};
}
destroyOneResponse ServerHandler::destroyOneHandleFunc(destroyOneParams params)
{
    // not implemented
    return destroyOneResponse{};
}
findTodosResponse ServerHandler::findTodosHandleFunc(findTodosParams params)
{
    // not implemented
    return findTodosResponse{};
}
updateOneResponse ServerHandler::updateOneHandleFunc(updateOneParams params)
{
    // not implemented
    return updateOneResponse{};
}

