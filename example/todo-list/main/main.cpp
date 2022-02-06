#include "TodosApi.h"
#include "curlppclient.h"
#include <iostream>
// #include <boost/stacktrace.hpp>
#include "openapi/runtime/auth.h"
#include "openapi/runtime/executor.h"

using namespace openapi;

int main()
{
    // Set the async launcher for runtime
    Executor::GetInstance().SetExecutor([](std::function<void(void)> f)
    {
        std::thread(f).detach();
    });

    try
    {
        ClientConfig cfg = {
            "localhost",
            "12345",
            "/",
            };
        
        std::shared_ptr<IClient> cli = std::make_shared<CurlPPClient>(cfg);

        TodosApiService ts(cli);
        ts.SetDefaultAuth(APIAuth("x-todolist-token", "example token"));
        {
            findTodosParams p;
            // p.limit = 3;
            findTodosResponse r = ts.findTodos(p);
            std::cout << "Find Todo: " << r << std::endl;
        }

        {
            addOneParams p;
            p.body = Item{0, openapi::StringT("hello")};
            addOneResponse r = ts.addOne(p);
            std::cout << "Add one: " << r << std::endl;
        }

        {
            destroyOneParams p;
            p.id = 0;
            destroyOneResponse r = ts.destroyOne(p);
            std::cout << "destroy one: " << r << std::endl;
        }
    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        // std::cout << boost::stacktrace::stacktrace();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}