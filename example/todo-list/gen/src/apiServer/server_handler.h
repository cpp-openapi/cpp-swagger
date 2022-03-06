#pragma once

#include "TodosApi.h"


#include <memory>
#include <functional>


namespace openapi{


// user needs to override this
class ServerHandler
{
public:
    virtual addOneResponse addOneHandleFunc(addOneParams params);
    virtual destroyOneResponse destroyOneHandleFunc(destroyOneParams params);
    virtual findTodosResponse findTodosHandleFunc(findTodosParams params);
    virtual updateOneResponse updateOneHandleFunc(updateOneParams params);
};



class Server
{
public:
    // passs in user implemented handler
    Server(std::shared_ptr<ServerHandler> handler);
    // inside this convert req to params
    // read from req and fill resp
    // TODO: refactor for main
    //void HandleHttp(IOASClientRequest & req, IOASClientResponse &resp);

    bool GetHandlerFunc(std::string const & method, std::string const & path, PathParamValue &paramsRet, std::function<void(IOASClientRequest &, IOASClientResponse &)> & ret);

    std::shared_ptr<ServerHandler> handler_;
    Router<std::function<void(IOASClientRequest &, IOASClientResponse &)>> router_;
};


}// namespace openapi