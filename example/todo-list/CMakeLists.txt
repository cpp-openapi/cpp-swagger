openapi_generate(
    generate-todo-list-example
    SPEC "${CMAKE_CURRENT_SOURCE_DIR}/swagger.yml"
    OUTDIR "${CMAKE_CURRENT_SOURCE_DIR}/gen"
)

if(CPP_SWAGGER_AddExamplesSubDir)
    add_subdirectory(gen/src)
    add_subdirectory(main)
    add_subdirectory(server)
endif()