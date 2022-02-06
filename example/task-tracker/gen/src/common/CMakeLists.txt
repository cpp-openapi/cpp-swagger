file(GLOB SOURCES
    *.h
    *.cpp
)

add_library(issue_Tracker_API_common
    STATIC ${SOURCES}
)

target_include_directories(issue_Tracker_API_common
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(issue_Tracker_API_common
    PUBLIC openapi_json openapi_nlohmann_json openapi_runtime
)

target_compile_definitions(
    issue_Tracker_API_common PUBLIC ${OPENAPI_JSON}=1
)

# once link to runtime this can be removed
if(OPENAPI_UTF16_STRINGS)
    target_compile_definitions(issue_Tracker_API_common PUBLIC OPENAPI_UTF16_STRINGS=1)
    message(STATUS "generated model uses OPENAPI_UTF16_STRINGS=1")
endif()