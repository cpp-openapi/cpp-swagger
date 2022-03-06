#include "handler.h"
#include <iostream>

using namespace openapi;

void TodoListHandler::Log(std::string const & msg)
{
    std::cout << "[todolist]: "<< msg << std::endl;
}

addOneResponse TodoListHandler::addOneHandleFunc(addOneParams params)
{
    std::lock_guard<std::mutex> guard(this->lock_);
    this->Log("AddOne call");

    if(!params.body.has_value())
    {
        // error
        throw std::invalid_argument("body item is missing");
        return addOneResponse{};
    }

    std::shared_ptr<Item> item = params.body.value();
    if(!item->id)
    {
        throw std::invalid_argument("body item.id is missing");
    }
    int id = item->id.value();

    this->items_[id] = item; // make copy?
    addOneResponse resp;
    resp.code = 200;
    resp.payload = *item;
    this->Log("AddOne call result: " + openapi::ToStdString(Json::Serialize(item).c_str()));
    return resp;
}


destroyOneResponse TodoListHandler::destroyOneHandleFunc(destroyOneParams params)
{
    this->Log("destroy one call");
    return destroyOneResponse{};
}
    
findTodosResponse TodoListHandler::findTodosHandleFunc(findTodosParams params)
{
    this->Log("findTodos call");
    return findTodosResponse{};
}

updateOneResponse TodoListHandler::updateOneHandleFunc(updateOneParams params) 
{
    this->Log("updateOne call");
    return updateOneResponse{};
}