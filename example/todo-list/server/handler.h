#pragma once

// impl of the todo list

#include <mutex>
#include <map>
#include <memory>
#include "Item.h"
#include "TodosApi.h"

#include "server_handler.h"

namespace openapi{

class TodoListHandler : public ServerHandler
{
public:
    addOneResponse addOneHandleFunc(addOneParams params) override;
    destroyOneResponse destroyOneHandleFunc(destroyOneParams params) override;
    findTodosResponse findTodosHandleFunc(findTodosParams params) override;
    updateOneResponse updateOneHandleFunc(updateOneParams params) override;
    void Log(std::string const & msg);
private:
    std::mutex lock_;
    std::map<int,std::shared_ptr<openapi::Item>> items_;
};

} // namespace openapi