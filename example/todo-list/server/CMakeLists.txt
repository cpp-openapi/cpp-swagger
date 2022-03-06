file(GLOB SOURCES
    *.h
    *.cpp
)

# filter out tests
list(FILTER SOURCES EXCLUDE REGEX .*_test\\.cpp)

set(Boost_USE_STATIC_LIBS ON)
ADD_DEFINITIONS("-DBOOST_ALL_NO_LIB")
find_package(Boost REQUIRED)

add_executable(todo_server ${SOURCES}
)

target_include_directories(todo_server
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(todo_server
    PUBLIC a_To_Do_list_application_common a_To_Do_list_application_model a_To_Do_list_application_apiServer
    ${Boost_LIBRARIES}
)

if(NOT WIN32)
    # for stack trace
    target_link_libraries(todo_server
    PUBLIC pthread dl
    )
endif()
