#pragma once
#include <optional>
#include "openapi/runtime/client.h"
#include "openapi/runtime/request.h"
#include "openapi/runtime/response.h"
#include "openapi/runtime/auth.h"
#include "ACommentToCreate.h"
#include "Comment.h"
#include "Error.h"
#include "Task.h"
#include "TaskCard.h"
#include "ValidationError.h"

#include <vector>

namespace openapi {


// class name TasksApi


struct addCommentToTaskParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    std::optional<std::shared_ptr<ACommentToCreate>> body;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct addCommentToTaskResponse {
    // no return type
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const addCommentToTaskResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const addCommentToTaskResponse& resp);

struct createTaskParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<std::shared_ptr<Task>> body;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct createTaskResponse {
    // no return type
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const createTaskResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const createTaskResponse& resp);

struct deleteTaskParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct deleteTaskResponse {
    // no return type
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const deleteTaskResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const deleteTaskResponse& resp);

struct getTaskCommentsParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    std::optional<int> pageSize;
    std::optional<openapi::string_t> since;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct getTaskCommentsResponse {
    std::optional<std::vector<Comment>> payload;
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const getTaskCommentsResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const getTaskCommentsResponse& resp);

struct getTaskDetailsParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct getTaskDetailsResponse {
    std::optional<Task> payload;
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const getTaskDetailsResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const getTaskDetailsResponse& resp);

struct listTasksParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> sinceId;
    std::optional<std::vector<openapi::string_t>> tags;
    std::optional<std::vector<openapi::string_t>> status;
    std::optional<int> pageSize;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct listTasksResponse {
    std::optional<std::vector<TaskCard>> payload;
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const listTasksResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const listTasksResponse& resp);

struct updateTaskParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    std::optional<std::shared_ptr<Task>> body;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct updateTaskResponse {
    std::optional<Task> payload;
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const updateTaskResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const updateTaskResponse& resp);

struct uploadTaskFileParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    std::optional<openapi::string_t> file;
    std::optional<openapi::string_t> description;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct uploadTaskFileResponse {
    // no return type
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const uploadTaskFileResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const uploadTaskFileResponse& resp);

class TasksApiService{
public:
    TasksApiService(std::shared_ptr<IClient> cli):_cli(cli) {};
    void SetDefaultAuth(AuthInfoWriter auth);
    addCommentToTaskResponse addCommentToTask(addCommentToTaskParams params);
    createTaskResponse createTask(createTaskParams params);
    deleteTaskResponse deleteTask(deleteTaskParams params);
    getTaskCommentsResponse getTaskComments(getTaskCommentsParams params);
    getTaskDetailsResponse getTaskDetails(getTaskDetailsParams params);
    listTasksResponse listTasks(listTasksParams params);
    updateTaskResponse updateTask(updateTaskParams params);
    uploadTaskFileResponse uploadTaskFile(uploadTaskFileParams params);

private:
    std::shared_ptr<IClient> _cli;
    AuthInfoWriter _auth = nullptr;
};

} // namespace openapi