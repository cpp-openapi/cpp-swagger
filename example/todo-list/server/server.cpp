//
// Copyright (c) 2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: HTTP server, small
//
//------------------------------------------------------------------------------

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

#include <boost/stacktrace.hpp>

#include "openapi/runtime/request.h"
#include "server_handler.h"
#include "handler.h"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

namespace my_program_state
{

    static openapi::Server g_Server(std::make_shared<openapi::TodoListHandler>());
    // static std::shared_ptr<openapi::ServerHandler> g_h =  std::make_shared<openapi::TodoListHandler>();
}

class http_connection : public std::enable_shared_from_this<http_connection>
{
public:
    http_connection(tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

    // Initiate the asynchronous operations associated with the connection.
    void
    start()
    {
        read_request();
        check_deadline();
    }

private:
    // The socket for the currently connected client.
    tcp::socket socket_;

    // The buffer for performing reads.
    beast::flat_buffer buffer_{8192};

    // The request message.
    http::request<http::dynamic_body> request_;

    // The response message.
    http::response<http::dynamic_body> response_;

    // The timer for putting a deadline on connection processing.
    net::steady_timer deadline_{
        socket_.get_executor(), std::chrono::seconds(60)};

    // Asynchronously receive a complete request message.
    void
    read_request()
    {
        auto self = shared_from_this();

        http::async_read(
            socket_,
            buffer_,
            request_,
            [self](beast::error_code ec,
                std::size_t bytes_transferred)
            {
                boost::ignore_unused(bytes_transferred);
                if(!ec)
                    self->process_request();
            });
    }

    // Determine what needs to be done with the request message.
    void
    process_request()
    {
        // convert beast requeset to oai request
        std::shared_ptr<IOASClientRequest> req = std::make_shared<ClientRequestImpl>();
        std::shared_ptr<IOASClientResponse> resp = std::make_shared<ClientResponseImpl>();
        
        
        bool reqFail = false;
        std::string errorStr;
        
        // convert HTTP method
        switch(request_.method())
        {
            case http::verb::get:
                req->SetMethod("GET");
                break;
            case http::verb::post:
                req->SetMethod("POST");
                break;
            case http::verb::put:
                req->SetMethod("PUT");
                break;
            case http::verb::patch:
                req->SetMethod("PATCH");
                break;
            default:
                reqFail = true;
                errorStr += "http method not recognized";
        }
        
        // TODO fail early

        // convert PATH
        std::string pathAndQuery = request_.target().to_string();
        std::vector<std::string> urlParts = openapi::SplitStdString(pathAndQuery, '?');

        std::string path;
        if (urlParts.size() > 0)
        {
            path = urlParts[0];
        }

        openapi::PathParamValue ppret;
        std::function<void(IOASClientRequest &, IOASClientResponse &)> handlerFuncRet;
        bool hasHandler = my_program_state::g_Server.GetHandlerFunc(req->GetMethod(), path, ppret, handlerFuncRet);

        response_.version(request_.version());
        response_.keep_alive(false);
        if(!hasHandler)
        {
            response_.result(http::status::not_found);
            response_.set(http::field::content_type, "text/plain");
            beast::ostream(response_.body()) << "Path:" << path << "not found \r\n";    
        }else{
            // convert path params
            for(std::pair<std::string,std::string> const & pathParam: ppret)
            {
                req->SetPathParam(pathParam.first, pathParam.second);
            }
            // convert header
            for (auto& h : request_.base()) {
                req->SetHeaderParam(h.name_string().to_string(), h.value().to_string());
            }
            // query params
            std::string query;
            if (urlParts.size() > 1)
            {
                query = openapi::JoinStrings(std::vector<std::string>(urlParts.begin()+1,urlParts.end()), '?');
                std::vector<std::string> queryKVs = openapi::SplitStdString(query, '&');
                for(std::string const & queryKV : queryKVs)
                {
                    std::vector<std::string> kv = openapi::SplitStdString(queryKV, '=');
                    if (kv.size() != 2){
                        // TODO fail req;
                        continue;
                    }
                    req->SetQueryParam(kv[0], kv[1]);
                }
            }

            // body
            std::string bodyStr = beast::buffers_to_string(request_.body().data());
            if (bodyStr.size() != 0)
            {
                req->SetBodyParam(bodyStr);
            }

            // invoke handler, resp should be filledup
            bool handlerOk = true;
            try
            {
                handlerFuncRet(*req,*resp);
            }
            catch(std::exception const& e)
            {
                // internal server error
                response_.result(http::status::internal_server_error);
                beast::ostream(response_.body()) << "\"error\": \""<< e.what() << "\"";
                // response_.set(http::field::content_type, "text/plain");
                //     response_.set(http::field::server, "Beast");
                handlerOk = false;
            }
            if(handlerOk)
            {
                // write beast resp
                response_.result(resp->GetCode());
                beast::ostream(response_.body()) << resp->GetBody();
            }
        }
        
        // write http response to wire
        write_response();
    }

    // Construct a response message based on the program state.
    // void
    // create_response()
    // {
    //     if(request_.target() == "/count")
    //     {
    //         response_.set(http::field::content_type, "text/html");
    //         beast::ostream(response_.body())
    //             << "<html>\n"
    //             <<  "<head><title>Request count</title></head>\n"
    //             <<  "<body>\n"
    //             <<  "<h1>Request count</h1>\n"
    //             <<  "<p>There have been "
    //             // <<  my_program_state::request_count()
    //             <<  " requests so far.</p>\n"
    //             <<  "</body>\n"
    //             <<  "</html>\n";
    //     }
    //     else if(request_.target() == "/time")
    //     {
    //         response_.set(http::field::content_type, "text/html");
    //         beast::ostream(response_.body())
    //             <<  "<html>\n"
    //             <<  "<head><title>Current time</title></head>\n"
    //             <<  "<body>\n"
    //             <<  "<h1>Current time</h1>\n"
    //             <<  "<p>The current time is "
    //             // <<  my_program_state::now()
    //             <<  " seconds since the epoch.</p>\n"
    //             <<  "</body>\n"
    //             <<  "</html>\n";
    //     }
    //     else
    //     {
    //         response_.result(http::status::not_found);
    //         response_.set(http::field::content_type, "text/plain");
    //         beast::ostream(response_.body()) << "File not found\r\n";
    //     }
    // }

    // Asynchronously transmit the response message.
    void
    write_response()
    {
        auto self = shared_from_this();

        response_.content_length(response_.body().size());

        http::async_write(
            socket_,
            response_,
            [self](beast::error_code ec, std::size_t)
            {
                self->socket_.shutdown(tcp::socket::shutdown_send, ec);
                self->deadline_.cancel();
            });
    }

    // Check whether we have spent enough time on this connection.
    void
    check_deadline()
    {
        auto self = shared_from_this();

        deadline_.async_wait(
            [self](beast::error_code ec)
            {
                if(!ec)
                {
                    // Close socket to cancel any outstanding operation.
                    self->socket_.close(ec);
                }
            });
    }
};

// "Loop" forever accepting new connections.
void
http_server(tcp::acceptor& acceptor, tcp::socket& socket)
{
  acceptor.async_accept(socket,
      [&](beast::error_code ec)
      {
          if(!ec)
              std::make_shared<http_connection>(std::move(socket))->start();
          http_server(acceptor, socket);
      });
}

int
main(int argc, char* argv[])
{
    try
    {
        // Check command line arguments.
        // if(argc != 3)
        // {
        //     std::cerr << "Usage: " << argv[0] << " <address> <port>\n";
        //     std::cerr << "  For IPv4, try:\n";
        //     std::cerr << "    receiver 0.0.0.0 80\n";
        //     std::cerr << "  For IPv6, try:\n";
        //     std::cerr << "    receiver 0::0 80\n";
        //     return EXIT_FAILURE;
        // }

        auto const address = net::ip::make_address("0.0.0.0");
        unsigned short port = static_cast<unsigned short>(std::atoi("12345"));

        net::io_context ioc{1};

        tcp::acceptor acceptor{ioc, {address, port}};
        tcp::socket socket{ioc};
        http_server(acceptor, socket);

        ioc.run();
    }
    catch(std::exception const& e)
    {
        std::cerr << boost::stacktrace::stacktrace();
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}