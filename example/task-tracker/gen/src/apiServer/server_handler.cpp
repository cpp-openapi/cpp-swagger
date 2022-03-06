#include "server_handler.h"

using namespace openapi;

Server::Server(std::shared_ptr<ServerHandler> handler): handler_(handler), router_({})
{
    RouteBuilder<std::function<void(IOASClientRequest &, IOASClientResponse &)>> b;

    // std::function<void(IOASClientRequest & req, IOASClientResponse &resp)>
    b.AddRoute("POST", "/tasks/{id}/comments",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            addCommentToTaskParams params;
            params.ReadParams(req);
            addCommentToTaskResponse res = this->handler_->addCommentToTaskHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("POST", "/tasks",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            createTaskParams params;
            params.ReadParams(req);
            createTaskResponse res = this->handler_->createTaskHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("DELETE", "/tasks/{id}",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            deleteTaskParams params;
            params.ReadParams(req);
            deleteTaskResponse res = this->handler_->deleteTaskHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("GET", "/tasks/{id}/comments",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            getTaskCommentsParams params;
            params.ReadParams(req);
            getTaskCommentsResponse res = this->handler_->getTaskCommentsHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("GET", "/tasks/{id}",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            getTaskDetailsParams params;
            params.ReadParams(req);
            getTaskDetailsResponse res = this->handler_->getTaskDetailsHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("GET", "/tasks",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            listTasksParams params;
            params.ReadParams(req);
            listTasksResponse res = this->handler_->listTasksHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("PUT", "/tasks/{id}",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            updateTaskParams params;
            params.ReadParams(req);
            updateTaskResponse res = this->handler_->updateTaskHandleFunc(params);
            res.WriteResponse(resp);
        });
    b.AddRoute("POST", "/tasks/{id}/files",
        [this](IOASClientRequest & req, IOASClientResponse &resp)
        {
            
            uploadTaskFileParams params;
            params.ReadParams(req);
            uploadTaskFileResponse res = this->handler_->uploadTaskFileHandleFunc(params);
            res.WriteResponse(resp);
        });

    this->router_ = b.Build();
}

bool Server::GetHandlerFunc(std::string const & method, std::string const & path, PathParamValue &paramsRet, std::function<void(IOASClientRequest &, IOASClientResponse &)> & ret)
{
    bool ok = this->router_.LookUp(method, path, paramsRet, ret);
    return ok;
}



addCommentToTaskResponse ServerHandler::addCommentToTaskHandleFunc(addCommentToTaskParams params)
{
    // not implemented
    return addCommentToTaskResponse{};
}
createTaskResponse ServerHandler::createTaskHandleFunc(createTaskParams params)
{
    // not implemented
    return createTaskResponse{};
}
deleteTaskResponse ServerHandler::deleteTaskHandleFunc(deleteTaskParams params)
{
    // not implemented
    return deleteTaskResponse{};
}
getTaskCommentsResponse ServerHandler::getTaskCommentsHandleFunc(getTaskCommentsParams params)
{
    // not implemented
    return getTaskCommentsResponse{};
}
getTaskDetailsResponse ServerHandler::getTaskDetailsHandleFunc(getTaskDetailsParams params)
{
    // not implemented
    return getTaskDetailsResponse{};
}
listTasksResponse ServerHandler::listTasksHandleFunc(listTasksParams params)
{
    // not implemented
    return listTasksResponse{};
}
updateTaskResponse ServerHandler::updateTaskHandleFunc(updateTaskParams params)
{
    // not implemented
    return updateTaskResponse{};
}
uploadTaskFileResponse ServerHandler::uploadTaskFileHandleFunc(uploadTaskFileParams params)
{
    // not implemented
    return uploadTaskFileResponse{};
}

