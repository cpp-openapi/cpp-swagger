# this is a example program that uses the generated client

add_executable("main" main.cpp)
# target_include_directories(
#   main
# #  PUBLIC ${Boost_INCLUDE_DIR}
# )
target_link_libraries("main"
    PRIVATE a_To_Do_list_application_api
    PUBLIC openapi_runtime # for auth
    openapi_client_curlpp
)