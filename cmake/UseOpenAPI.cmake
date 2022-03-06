find_package(Java 1.8 REQUIRED)
include(UseJava)

set(OPENAPI_JAR_BIN_DIR ${CMAKE_BINARY_DIR}/bin)

unset(OPENAPI_GENERATOR CACHE)
find_jar(OPENAPI_GENERATOR openapi-generator-cli-5.3.1
    PATHS ${OPENAPI_JAR_BIN_DIR}
)

if (NOT OPENAPI_GENERATOR)
    message(VERBOSE "openapi cli jar not found downloading to ${OPENAPI_JAR_BIN_DIR}")
    file(DOWNLOAD
        https://repo1.maven.org/maven2/org/openapitools/openapi-generator-cli/5.3.1/openapi-generator-cli-5.3.1.jar
        ${OPENAPI_JAR_BIN_DIR}/openapi-generator-cli-5.3.1.jar
        EXPECTED_HASH  SHA256=81DC1B3FB1102B43BECD2F46098CFD861E9C4E84FBEBB534AD67D7C6B0EEFF77
        # SHOW_PROGRESS
    )
    message(VERBOSE "Find jar after download")
    find_jar(OPENAPI_GENERATOR openapi-generator-cli-5.3.1
        PATHS ${OPENAPI_JAR_BIN_DIR}
    )
    if (NOT OPENAPI_GENERATOR)
        message(FATAL_ERROR "jar not found after download.")
    endif()
else()
message(VERBOSE "Found jar ${OPENAPI_GENERATOR}")
endif()
# calculate hash in powershell:  Get-FileHash -Algorithm SHA256 <file name>

# add exe to path so that cmake can search
# LIST(APPEND CMAKE_PROGRAM_PATH "${openapi-generator-jar_SOURCE_DIR}")

message(VERBOSE "Check Java Version.")
execute_process(
    COMMAND ${Java_JAVA_EXECUTABLE} --version
    # COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
)

message(VERBOSE "Check openapi generator version")
execute_process(
    COMMAND ${Java_JAVA_EXECUTABLE} -jar ${OPENAPI_GENERATOR} version
    # COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
)

# generate generators. should not be executed again.
# cmake --build build --target generator-gen
# add_custom_target(
#     generator-gen
#     COMMAND ${Java_JAVA_EXECUTABLE} -jar ${OPENAPI_GENERATOR} meta -o generator -n cpp-openapi -p cpp.openapi
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
# )

message(VERBOSE "Finding maven.")
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
    message(VERBOSE "mvn found in ${MAVEN}")
    execute_process(
        COMMAND ${MAVEN} --version
        # COMMAND_ECHO STDOUT
    )
endif()

# build generator
# cmake --build build --target mvn-package

file(GLOB GENERATOR_SOURCES
    ${cpp-swagger_SOURCE_DIR}/generator/src/main/java/cpp/openapi/*.java
    ${cpp-swagger_SOURCE_DIR}/generator/src/main/resources/cpp-openapi/**/*.mustache
    ${cpp-swagger_SOURCE_DIR}/generator/src/main/resources/cpp-openapi/*.mustache
)

add_custom_command(
    OUTPUT ${cpp-swagger_SOURCE_DIR}/generator/target/cpp-openapi-openapi-generator-1.0.0.jar
    COMMAND ${MAVEN} package -DskipTests
    WORKING_DIRECTORY ${cpp-swagger_SOURCE_DIR}/generator
    DEPENDS ${GENERATOR_SOURCES}
)

# generator function
# openapi_generate(SPEC myspec OUTDIR myoutdir)
function(openapi_generate TARGET)
set(_spec)
set(_outdir)
set(_state "name")

foreach (arg IN LISTS ARGN)
    if (_state STREQUAL "name")
        if (arg STREQUAL "SPEC")
            set(_state "spec")
        elseif (arg STREQUAL "OUTDIR")
            set(_state "outdir")
        endif ()
    elseif (_state STREQUAL "spec")
        if (arg STREQUAL "OUTDIR")
            set(_state "outdir")
        else ()
            set(_spec ${arg})
        endif ()
    elseif (_state STREQUAL "outdir")
        if (arg STREQUAL "SPEC")
            set(_state "spec")
        else ()
            set(_outdir ${arg})
        endif ()
    endif ()
endforeach ()

if(NOT _spec)
    message(FATAL_ERROR "SPEC not set.")
endif()
if(NOT _outdir)
    message(FATAL_ERROR "OUTDIR not set.")
endif()

set(OPENAPI_JAR_SEPARATOR ":")
if(WIN32)
set(OPENAPI_JAR_SEPARATOR ";")
endif()
add_custom_target(
    ${TARGET}
    DEPENDS generator-jar
    COMMAND "${Java_JAVA_EXECUTABLE}"
        "-cp" "${OPENAPI_GENERATOR}${OPENAPI_JAR_SEPARATOR}${cpp-swagger_SOURCE_DIR}/generator/target/cpp-openapi-openapi-generator-1.0.0.jar"
        "org.openapitools.codegen.OpenAPIGenerator" "generate"
        "-g" "cpp-openapi"
        "-i" "${_spec}"
        "-o" "${_outdir}"
    WORKING_DIRECTORY ${cpp-swagger_SOURCE_DIR}
)
endfunction()