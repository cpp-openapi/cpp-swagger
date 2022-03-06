#pragma once

#include "ACommentToCreate.h"
#include "Comment.h"
#include "Error.h"
#include "Task.h"
#include "TaskCard.h"
#include "ValidationError.h"

#include <vector>

#include <functional>
#include "openapi/runtime/router.h"


namespace openapi {



// class name TasksApi
struct addCommentToTaskParams {
    std::optional<int> id;
    std::optional<std::shared_ptr<ACommentToCreate>> body;
    void ReadParams(IOASClientRequest & req);
};

struct addCommentToTaskResponse {
    // no return type
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const addCommentToTaskResponse& resp);
};

// function user needs to implement
typedef std::function<addCommentToTaskResponse(addCommentToTaskParams)> addCommentToTaskHandlerFuncType;


// class name TasksApi
struct createTaskParams {
    std::optional<std::shared_ptr<Task>> body;
    void ReadParams(IOASClientRequest & req);
};

struct createTaskResponse {
    // no return type
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const createTaskResponse& resp);
};

// function user needs to implement
typedef std::function<createTaskResponse(createTaskParams)> createTaskHandlerFuncType;


// class name TasksApi
struct deleteTaskParams {
    std::optional<int> id;
    void ReadParams(IOASClientRequest & req);
};

struct deleteTaskResponse {
    // no return type
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const deleteTaskResponse& resp);
};

// function user needs to implement
typedef std::function<deleteTaskResponse(deleteTaskParams)> deleteTaskHandlerFuncType;


// class name TasksApi
struct getTaskCommentsParams {
    std::optional<int> id;
    std::optional<int> pageSize;
    std::optional<openapi::string_t> since;
    void ReadParams(IOASClientRequest & req);
};

struct getTaskCommentsResponse {
    std::optional<std::vector<Comment>> payload;
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const getTaskCommentsResponse& resp);
};

// function user needs to implement
typedef std::function<getTaskCommentsResponse(getTaskCommentsParams)> getTaskCommentsHandlerFuncType;


// class name TasksApi
struct getTaskDetailsParams {
    std::optional<int> id;
    void ReadParams(IOASClientRequest & req);
};

struct getTaskDetailsResponse {
    std::optional<Task> payload;
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const getTaskDetailsResponse& resp);
};

// function user needs to implement
typedef std::function<getTaskDetailsResponse(getTaskDetailsParams)> getTaskDetailsHandlerFuncType;


// class name TasksApi
struct listTasksParams {
    std::optional<int> sinceId;
    std::optional<std::vector<openapi::string_t>> tags;
    std::optional<std::vector<openapi::string_t>> status;
    std::optional<int> pageSize;
    void ReadParams(IOASClientRequest & req);
};

struct listTasksResponse {
    std::optional<std::vector<TaskCard>> payload;
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const listTasksResponse& resp);
};

// function user needs to implement
typedef std::function<listTasksResponse(listTasksParams)> listTasksHandlerFuncType;


// class name TasksApi
struct updateTaskParams {
    std::optional<int> id;
    std::optional<std::shared_ptr<Task>> body;
    void ReadParams(IOASClientRequest & req);
};

struct updateTaskResponse {
    std::optional<Task> payload;
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const updateTaskResponse& resp);
};

// function user needs to implement
typedef std::function<updateTaskResponse(updateTaskParams)> updateTaskHandlerFuncType;


// class name TasksApi
struct uploadTaskFileParams {
    std::optional<int> id;
    std::optional<openapi::string_t> file;
    std::optional<openapi::string_t> description;
    void ReadParams(IOASClientRequest & req);
};

struct uploadTaskFileResponse {
    // no return type
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const uploadTaskFileResponse& resp);
};

// function user needs to implement
typedef std::function<uploadTaskFileResponse(uploadTaskFileParams)> uploadTaskFileHandlerFuncType;



} // namespace openapi