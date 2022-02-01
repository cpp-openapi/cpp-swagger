cmake_policy(SET CMP0048 NEW) # set version in project
project(cpp-swagger VERSION 0.0.1 LANGUAGES CXX)

cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 17)

find_package(Java 1.8 REQUIRED)
include(UseJava)

set(OPENAPI_JAR_BIN_DIR ${CMAKE_BINARY_DIR}/bin)

unset(OPENAPI_GENERATOR CACHE)
find_jar(OPENAPI_GENERATOR openapi-generator-cli-5.3.1
    PATHS ${OPENAPI_JAR_BIN_DIR}
)

if (NOT OPENAPI_GENERATOR)
    message(STATUS "openapi cli jar not found downloading to ${OPENAPI_JAR_BIN_DIR}")
    file(DOWNLOAD
        https://repo1.maven.org/maven2/org/openapitools/openapi-generator-cli/5.3.1/openapi-generator-cli-5.3.1.jar
        ${OPENAPI_JAR_BIN_DIR}/openapi-generator-cli-5.3.1.jar
        EXPECTED_HASH  SHA256=81DC1B3FB1102B43BECD2F46098CFD861E9C4E84FBEBB534AD67D7C6B0EEFF77
        # SHOW_PROGRESS
    )
    message(STATUS "Find jar after download")
    find_jar(OPENAPI_GENERATOR openapi-generator-cli-5.3.1
        PATHS ${OPENAPI_JAR_BIN_DIR}
    )
    if (NOT OPENAPI_GENERATOR)
        message(FATAL_ERROR "jar not found after download.")
    endif()
else()
message(STATUS "Found jar ${OPENAPI_GENERATOR}")
endif()
# calculate hash in powershell:  Get-FileHash -Algorithm SHA256 <file name>

# add exe to path so that cmake can search
# LIST(APPEND CMAKE_PROGRAM_PATH "${openapi-generator-jar_SOURCE_DIR}")

message(STATUS "Check Java Version.")
execute_process(
    COMMAND ${Java_JAVA_EXECUTABLE} --version
    COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
)

message(STATUS "Check openapi generator version")
execute_process(
    COMMAND ${Java_JAVA_EXECUTABLE} -jar ${OPENAPI_GENERATOR} version
    COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
)

# generate generators. should not be executed again.
# cmake --build build --target generator-gen
# add_custom_target(
#     generator-gen
#     COMMAND ${Java_JAVA_EXECUTABLE} -jar ${OPENAPI_GENERATOR} meta -o generator -n cpp-openapi -p cpp.openapi
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
# )

message(STATUS "Finding maven.")
if(WIN32)
find_program (
    MAVEN
    mvn.cmd
)
else()
find_program (
    MAVEN
    mvn
)
endif()
if(NOT MAVEN)
    message(FATAL_ERROR "mvn not found")
else()
    message(STATUS "mvn found in ${MAVEN}")
    execute_process(
        COMMAND ${MAVEN} --version
        COMMAND_ECHO STDOUT
    )
endif()

# build generator
# cmake --build build --target mvn-package
add_custom_target(
    mvn-package
    COMMAND ${MAVEN} package -DskipTests
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/generator
)

# cmake --build build --target generate-example
set(OPENAPI_JAR_SEPARATOR ":")
if(WIN32)
set(OPENAPI_JAR_SEPARATOR ";")
endif()
add_custom_target(
    generate-example
    DEPENDS mvn-package
    COMMAND "${Java_JAVA_EXECUTABLE}"
        "-cp" "${OPENAPI_GENERATOR}${OPENAPI_JAR_SEPARATOR}${CMAKE_CURRENT_SOURCE_DIR}/generator/target/cpp-openapi-openapi-generator-1.0.0.jar"
        "org.openapitools.codegen.OpenAPIGenerator" "generate"
        "-g" "cpp-openapi"
        "-i" "${CMAKE_CURRENT_SOURCE_DIR}/example/todo-list/swagger.yml"
        "-o" "${CMAKE_CURRENT_SOURCE_DIR}/example/todo-list/gen"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# add_custom_target(
#     build-all
#     DEPENDS mvn-package generate-example
# )
enable_testing()
add_subdirectory(example)