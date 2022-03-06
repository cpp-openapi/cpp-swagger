file(GLOB SOURCES
    *.h
    *.cpp
)

add_library(a_To_Do_list_application_apiServer
    STATIC ${SOURCES}
)

target_include_directories(a_To_Do_list_application_apiServer
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(a_To_Do_list_application_apiServer
    PUBLIC a_To_Do_list_application_common 
    a_To_Do_list_application_model
    openapi_runtime_middleware
)