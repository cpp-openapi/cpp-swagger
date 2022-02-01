file(GLOB SOURCES
    *.h
    *.cpp
)

# filter out tests
list(FILTER SOURCES EXCLUDE REGEX .*_test\\.cpp)

add_library(a_To_Do_list_application_model
    STATIC ${SOURCES}
)

target_include_directories(a_To_Do_list_application_model
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(a_To_Do_list_application_model
    PUBLIC openapi_json openapi_nlohmann_json openapi_runtime
)

target_compile_definitions(
    a_To_Do_list_application_model PUBLIC ${OPENAPI_JSON}=1
)

# once link to runtime this can be removed
if(OPENAPI_UTF16_STRINGS)
    target_compile_definitions(a_To_Do_list_application_model PUBLIC OPENAPI_UTF16_STRINGS=1)
    message(STATUS "generated model uses OPENAPI_UTF16_STRINGS=1")
endif()

# testing
file(GLOB TEST_SOURCES
    *_test.cpp
)

foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    
    target_link_libraries(${test_name} PRIVATE gtest_main a_To_Do_list_application_model)

    add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endforeach()