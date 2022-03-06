cmake_policy(SET CMP0048 NEW) # set version in project
project(cpp-swagger VERSION 0.0.1 LANGUAGES CXX)

cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 17)

set(CPP_SWAGGER_MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CPP_SWAGGER_MAIN_PROJECT ON)
endif()
option(CPP_SWAGGER_BuildTests     "Build the unit tests when BUILD_TESTING is enabled." ${CPP_SWAGGER_MAIN_PROJECT})
option(CPP_SWAGGER_BuildExamples  "Build examples"                                      ${CPP_SWAGGER_MAIN_PROJECT})

# set(CPP_SWAGGER_AddExamplesSubDir ON)
option(CPP_SWAGGER_AddExamplesSubDir  
    "Include examples in cmake configure. Turn it off if you are regenerating exampels for build speed up" 
    OFF
)

# hack for UseOpenAPI adds a target
# add openapi cmake module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(UseOpenAPI)
add_custom_target(
    generator-jar ALL
    DEPENDS ${cpp-swagger_SOURCE_DIR}/generator/target/cpp-openapi-openapi-generator-1.0.0.jar
)

# cmake --build build --target generate-example
if(CPP_SWAGGER_BuildTests)
    enable_testing()
endif()
if(CPP_SWAGGER_BuildExamples)
    add_subdirectory(example)
    
    # generate all for CI
    add_custom_target(build-all-ci)
    add_dependencies(build-all-ci generate-task-tracker-example generate-todo-list-example)
endif()

add_subdirectory(example/todo-list/gen/src)
add_subdirectory(example/todo-list/main)
add_subdirectory(example/todo-list/server)

add_subdirectory(example/task-tracker/gen/src)