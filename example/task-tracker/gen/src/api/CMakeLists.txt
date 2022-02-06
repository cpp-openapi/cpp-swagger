file(GLOB SOURCES
    *.h
    *.cpp
)

add_library(issue_Tracker_API_api
    STATIC ${SOURCES}
)

target_include_directories(issue_Tracker_API_api
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(issue_Tracker_API_api
    PUBLIC issue_Tracker_API_common issue_Tracker_API_model
)