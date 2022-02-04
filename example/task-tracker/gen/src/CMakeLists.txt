cmake_policy(SET CMP0048 NEW) # set version in project
project(issue_Tracker_API VERSION 0.0.1 LANGUAGES CXX)

cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 17)

message(STATUS "Fetching openapi-runtime")
include(FetchContent)
FetchContent_Declare(openapi_runtime
  GIT_REPOSITORY https://github.com/cpp-openapi/runtime.git
  GIT_TAG d3368e18470ac0e25a5d3e1b51c0fef529537168)
# only support wchar for now
set(OPENAPI_UTF16_STRINGS ON CACHE BOOL "" FORCE)
set(OPENAPI_JSON "OPENAPI_NLOHMANNJSON")
FetchContent_GetProperties(openapi_runtime)
if(NOT openapi_runtime_POPULATED)
  FetchContent_Populate(openapi_runtime)
  add_subdirectory(${openapi_runtime_SOURCE_DIR} ${openapi_runtime_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


# enable tests from now on
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
message(STATUS "Fetching googletest")
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(model)