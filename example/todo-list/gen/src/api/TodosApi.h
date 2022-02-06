#pragma once
#include <optional>
#include "openapi/runtime/client.h"
#include "openapi/runtime/request.h"
#include "openapi/runtime/response.h"
#include "openapi/runtime/auth.h"
#include "Error.h"
#include "Item.h"

namespace openapi {


// class name TodosApi


struct addOneParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<Item> body;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct addOneResponse {
    std::optional<Item> payload;
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const addOneResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const addOneResponse& resp);

struct destroyOneParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct destroyOneResponse {
    // no return type
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const destroyOneResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const destroyOneResponse& resp);

struct findTodosParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> since;
    std::optional<int> limit;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct findTodosResponse {
    std::optional<std::vector<Item>> payload;
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const findTodosResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const findTodosResponse& resp);

struct updateOneParams {
    static std::string const ContentType;
    static std::string const PathPattern;
    static std::string const Method;
    std::optional<int> id;
    std::optional<Item> body;
    void WriteParams(std::shared_ptr<IOASClientRequest> req) const;
};

struct updateOneResponse {
    std::optional<Item> payload;
    int code;
    void ReadResponse(std::shared_ptr<IOASClientResponse> resp);
    friend std::ostream& operator<<(std::ostream& os, const updateOneResponse& resp);
};

std::ostream& operator<<(std::ostream& os, const updateOneResponse& resp);

class TodosApiService{
public:
    TodosApiService(std::shared_ptr<IClient> cli):_cli(cli) {};
    void SetDefaultAuth(AuthInfoWriter auth);
    addOneResponse addOne(addOneParams params);
    destroyOneResponse destroyOne(destroyOneParams params);
    findTodosResponse findTodos(findTodosParams params);
    updateOneResponse updateOne(updateOneParams params);

private:
    std::shared_ptr<IClient> _cli;
    AuthInfoWriter _auth = nullptr;
};

} // namespace openapi