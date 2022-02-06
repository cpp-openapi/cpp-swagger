#include "TasksApi.h"
#include "openapi/runtime/executor.h"

using namespace openapi;
// todo include str/json header


// class name TasksApi


std::string const addCommentToTaskParams::ContentType = "application/vnd.goswagger.examples.task-tracker.v1+json";
std::string const addCommentToTaskParams::PathPattern = "/tasks/{id}/comments";
std::string const addCommentToTaskParams::Method = "POST";
void addCommentToTaskParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", addCommentToTaskParams::ContentType);
    req->SetMethod(addCommentToTaskParams::Method);
    req->SetPathPattern(addCommentToTaskParams::PathPattern);
    if (this->id.has_value()){
        using V = remove_optional<decltype(this->id)>::type;
        req->SetPathParam<V>("id", this->id.value());
    }
    if (this->body.has_value()){
        using V = remove_optional<decltype(this->body)>::type;
        req->SetBodyParam(openapi::ToStdString(Json::Serialize(this->body)));
    }
}

void addCommentToTaskResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
}

std::ostream& openapi::operator<<(std::ostream& os, const addCommentToTaskResponse& resp)
{
    openapi::string_t payloadStr{};
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}

std::string const createTaskParams::ContentType = "application/vnd.goswagger.examples.task-tracker.v1+json";
std::string const createTaskParams::PathPattern = "/tasks";
std::string const createTaskParams::Method = "POST";
void createTaskParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", createTaskParams::ContentType);
    req->SetMethod(createTaskParams::Method);
    req->SetPathPattern(createTaskParams::PathPattern);
    if (this->body.has_value()){
        using V = remove_optional<decltype(this->body)>::type;
        req->SetBodyParam(openapi::ToStdString(Json::Serialize(this->body)));
    }
}

void createTaskResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
}

std::ostream& openapi::operator<<(std::ostream& os, const createTaskResponse& resp)
{
    openapi::string_t payloadStr{};
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}

std::string const deleteTaskParams::ContentType = "";
std::string const deleteTaskParams::PathPattern = "/tasks/{id}";
std::string const deleteTaskParams::Method = "DELETE";
void deleteTaskParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", deleteTaskParams::ContentType);
    req->SetMethod(deleteTaskParams::Method);
    req->SetPathPattern(deleteTaskParams::PathPattern);
    if (this->id.has_value()){
        using V = remove_optional<decltype(this->id)>::type;
        req->SetPathParam<V>("id", this->id.value());
    }
}

void deleteTaskResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
}

std::ostream& openapi::operator<<(std::ostream& os, const deleteTaskResponse& resp)
{
    openapi::string_t payloadStr{};
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}

std::string const getTaskCommentsParams::ContentType = "";
std::string const getTaskCommentsParams::PathPattern = "/tasks/{id}/comments";
std::string const getTaskCommentsParams::Method = "GET";
void getTaskCommentsParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", getTaskCommentsParams::ContentType);
    req->SetMethod(getTaskCommentsParams::Method);
    req->SetPathPattern(getTaskCommentsParams::PathPattern);
    if (this->id.has_value()){
        using V = remove_optional<decltype(this->id)>::type;
        req->SetPathParam<V>("id", this->id.value());
    }
    if (this->pageSize.has_value()){
        using V = remove_optional<decltype(this->pageSize)>::type;
        req->SetQueryParam<V>("pageSize", this->pageSize.value());
    }
    if (this->since.has_value()){
        using V = remove_optional<decltype(this->since)>::type;
        req->SetQueryParam<V>("since", this->since.value());
    }
}

void getTaskCommentsResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
    std::string strBody = resp->GetBody();
    if (strBody.size() == 0){
        return;
    }
    using U = typename remove_optional<decltype(this->payload)>::type;
    this->payload = Json::Deserialize<U>(openapi::StringT(strBody.c_str()));
}

std::ostream& openapi::operator<<(std::ostream& os, const getTaskCommentsResponse& resp)
{
    openapi::string_t payloadStr{};
    if(resp.payload.has_value())
    {
        payloadStr = Json::Serialize(resp.payload);
    }
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}

std::string const getTaskDetailsParams::ContentType = "";
std::string const getTaskDetailsParams::PathPattern = "/tasks/{id}";
std::string const getTaskDetailsParams::Method = "GET";
void getTaskDetailsParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", getTaskDetailsParams::ContentType);
    req->SetMethod(getTaskDetailsParams::Method);
    req->SetPathPattern(getTaskDetailsParams::PathPattern);
    if (this->id.has_value()){
        using V = remove_optional<decltype(this->id)>::type;
        req->SetPathParam<V>("id", this->id.value());
    }
}

void getTaskDetailsResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
    std::string strBody = resp->GetBody();
    if (strBody.size() == 0){
        return;
    }
    using U = typename remove_optional<decltype(this->payload)>::type;
    this->payload = Json::Deserialize<U>(openapi::StringT(strBody.c_str()));
}

std::ostream& openapi::operator<<(std::ostream& os, const getTaskDetailsResponse& resp)
{
    openapi::string_t payloadStr{};
    if(resp.payload.has_value())
    {
        payloadStr = Json::Serialize(resp.payload);
    }
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}

std::string const listTasksParams::ContentType = "";
std::string const listTasksParams::PathPattern = "/tasks";
std::string const listTasksParams::Method = "GET";
void listTasksParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", listTasksParams::ContentType);
    req->SetMethod(listTasksParams::Method);
    req->SetPathPattern(listTasksParams::PathPattern);
    if (this->sinceId.has_value()){
        using V = remove_optional<decltype(this->sinceId)>::type;
        req->SetQueryParam<V>("sinceId", this->sinceId.value());
    }
    if (this->tags.has_value()){
        using V = remove_optional<decltype(this->tags)>::type;
        req->SetQueryParam<V>("tags", this->tags.value());
    }
    if (this->status.has_value()){
        using V = remove_optional<decltype(this->status)>::type;
        req->SetQueryParam<V>("status", this->status.value());
    }
    if (this->pageSize.has_value()){
        using V = remove_optional<decltype(this->pageSize)>::type;
        req->SetQueryParam<V>("pageSize", this->pageSize.value());
    }
}

void listTasksResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
    std::string strBody = resp->GetBody();
    if (strBody.size() == 0){
        return;
    }
    using U = typename remove_optional<decltype(this->payload)>::type;
    this->payload = Json::Deserialize<U>(openapi::StringT(strBody.c_str()));
}

std::ostream& openapi::operator<<(std::ostream& os, const listTasksResponse& resp)
{
    openapi::string_t payloadStr{};
    if(resp.payload.has_value())
    {
        payloadStr = Json::Serialize(resp.payload);
    }
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}

std::string const updateTaskParams::ContentType = "application/vnd.goswagger.examples.task-tracker.v1+json";
std::string const updateTaskParams::PathPattern = "/tasks/{id}";
std::string const updateTaskParams::Method = "PUT";
void updateTaskParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", updateTaskParams::ContentType);
    req->SetMethod(updateTaskParams::Method);
    req->SetPathPattern(updateTaskParams::PathPattern);
    if (this->id.has_value()){
        using V = remove_optional<decltype(this->id)>::type;
        req->SetPathParam<V>("id", this->id.value());
    }
    if (this->body.has_value()){
        using V = remove_optional<decltype(this->body)>::type;
        req->SetBodyParam(openapi::ToStdString(Json::Serialize(this->body)));
    }
}

void updateTaskResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
    std::string strBody = resp->GetBody();
    if (strBody.size() == 0){
        return;
    }
    using U = typename remove_optional<decltype(this->payload)>::type;
    this->payload = Json::Deserialize<U>(openapi::StringT(strBody.c_str()));
}

std::ostream& openapi::operator<<(std::ostream& os, const updateTaskResponse& resp)
{
    openapi::string_t payloadStr{};
    if(resp.payload.has_value())
    {
        payloadStr = Json::Serialize(resp.payload);
    }
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}

std::string const uploadTaskFileParams::ContentType = "multipart/form-data";
std::string const uploadTaskFileParams::PathPattern = "/tasks/{id}/files";
std::string const uploadTaskFileParams::Method = "POST";
void uploadTaskFileParams::WriteParams(std::shared_ptr<IOASClientRequest> req) const
{
    req->SetHeaderParam("Content-Type", uploadTaskFileParams::ContentType);
    req->SetMethod(uploadTaskFileParams::Method);
    req->SetPathPattern(uploadTaskFileParams::PathPattern);
    if (this->id.has_value()){
        using V = remove_optional<decltype(this->id)>::type;
        req->SetPathParam<V>("id", this->id.value());
    }
    if (this->file.has_value()){
        using V = remove_optional<decltype(this->file)>::type;
    }
    if (this->description.has_value()){
        using V = remove_optional<decltype(this->description)>::type;
    }
}

void uploadTaskFileResponse::ReadResponse(std::shared_ptr<IOASClientResponse> resp)
{
    this->code = resp->GetCode();
}

std::ostream& openapi::operator<<(std::ostream& os, const uploadTaskFileResponse& resp)
{
    openapi::string_t payloadStr{};
    os << "[" << resp.code << "]: " << openapi::ToStdString(payloadStr); // TODO: wstream?
    return os;
}


void TasksApiService::SetDefaultAuth(AuthInfoWriter auth)
{
    this->_auth = auth;
}

addCommentToTaskResponse TasksApiService::addCommentToTask(addCommentToTaskParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<addCommentToTaskResponse>> p = std::make_shared<std::promise<addCommentToTaskResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            addCommentToTaskResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}

createTaskResponse TasksApiService::createTask(createTaskParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<createTaskResponse>> p = std::make_shared<std::promise<createTaskResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            createTaskResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}

deleteTaskResponse TasksApiService::deleteTask(deleteTaskParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<deleteTaskResponse>> p = std::make_shared<std::promise<deleteTaskResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            deleteTaskResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}

getTaskCommentsResponse TasksApiService::getTaskComments(getTaskCommentsParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<getTaskCommentsResponse>> p = std::make_shared<std::promise<getTaskCommentsResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            getTaskCommentsResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}

getTaskDetailsResponse TasksApiService::getTaskDetails(getTaskDetailsParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<getTaskDetailsResponse>> p = std::make_shared<std::promise<getTaskDetailsResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            getTaskDetailsResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}

listTasksResponse TasksApiService::listTasks(listTasksParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<listTasksResponse>> p = std::make_shared<std::promise<listTasksResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            listTasksResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}

updateTaskResponse TasksApiService::updateTask(updateTaskParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<updateTaskResponse>> p = std::make_shared<std::promise<updateTaskResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            updateTaskResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}

uploadTaskFileResponse TasksApiService::uploadTaskFile(uploadTaskFileParams params){

    std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
    params.WriteParams(req);
    
    if (this->_auth)
    {
        // add auth
        this->_auth(req);
    }

    std::shared_future<std::shared_ptr<IOASClientResponse>> respFuture = this->_cli->Do(req).share();

    std::shared_ptr<std::promise<uploadTaskFileResponse>> p = std::make_shared<std::promise<uploadTaskFileResponse>>();

    Executor::GetInstance().Submit([p, respFuture]() {
        try
        {
            // get future response
            std::shared_ptr<IOASClientResponse> resp = respFuture.get();
            uploadTaskFileResponse result;
            result.ReadResponse(resp);
            p->set_value(result);
        }
        catch([[maybe_unused]] const std::exception &e)
        {
            try
            {
                p->set_exception(std::current_exception());
            } catch(...) {}
        }
    });
    return p->get_future().get();
}


