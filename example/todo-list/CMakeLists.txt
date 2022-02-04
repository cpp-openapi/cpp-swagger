openapi_generate(
    generate-todo-list-example
    SPEC "${CMAKE_CURRENT_SOURCE_DIR}/swagger.yml"
    OUTDIR "${CMAKE_CURRENT_SOURCE_DIR}/gen"
)

add_subdirectory(gen/src)