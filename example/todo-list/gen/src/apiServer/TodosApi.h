#pragma once

#include "Error.h"
#include "Item.h"

#include <functional>
#include "openapi/runtime/router.h"


namespace openapi {



// class name TodosApi
struct addOneParams {
    std::optional<std::shared_ptr<Item>> body;
    void ReadParams(IOASClientRequest & req);
};

struct addOneResponse {
    std::optional<Item> payload;
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const addOneResponse& resp);
};

// function user needs to implement
typedef std::function<addOneResponse(addOneParams)> addOneHandlerFuncType;


// class name TodosApi
struct destroyOneParams {
    std::optional<int> id;
    void ReadParams(IOASClientRequest & req);
};

struct destroyOneResponse {
    // no return type
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const destroyOneResponse& resp);
};

// function user needs to implement
typedef std::function<destroyOneResponse(destroyOneParams)> destroyOneHandlerFuncType;


// class name TodosApi
struct findTodosParams {
    std::optional<int> since;
    std::optional<int> limit;
    void ReadParams(IOASClientRequest & req);
};

struct findTodosResponse {
    std::optional<std::vector<Item>> payload;
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const findTodosResponse& resp);
};

// function user needs to implement
typedef std::function<findTodosResponse(findTodosParams)> findTodosHandlerFuncType;


// class name TodosApi
struct updateOneParams {
    std::optional<int> id;
    std::optional<std::shared_ptr<Item>> body;
    void ReadParams(IOASClientRequest & req);
};

struct updateOneResponse {
    std::optional<Item> payload;
    int code;
    void WriteResponse(IOASClientResponse & resp);
    // friend std::ostream& operator<<(std::ostream& os, const updateOneResponse& resp);
};

// function user needs to implement
typedef std::function<updateOneResponse(updateOneParams)> updateOneHandlerFuncType;



} // namespace openapi