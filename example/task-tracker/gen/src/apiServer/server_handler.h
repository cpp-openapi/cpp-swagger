#pragma once

#include "TasksApi.h"


#include <memory>
#include <functional>


namespace openapi{


// user needs to override this
class ServerHandler
{
public:
    virtual addCommentToTaskResponse addCommentToTaskHandleFunc(addCommentToTaskParams params);
    virtual createTaskResponse createTaskHandleFunc(createTaskParams params);
    virtual deleteTaskResponse deleteTaskHandleFunc(deleteTaskParams params);
    virtual getTaskCommentsResponse getTaskCommentsHandleFunc(getTaskCommentsParams params);
    virtual getTaskDetailsResponse getTaskDetailsHandleFunc(getTaskDetailsParams params);
    virtual listTasksResponse listTasksHandleFunc(listTasksParams params);
    virtual updateTaskResponse updateTaskHandleFunc(updateTaskParams params);
    virtual uploadTaskFileResponse uploadTaskFileHandleFunc(uploadTaskFileParams params);
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