openapi_generate(
    generate-task-tracker-example
    SPEC "${CMAKE_CURRENT_SOURCE_DIR}/swagger.yml"
    OUTDIR "${CMAKE_CURRENT_SOURCE_DIR}/gen"
)

if(CPP_SWAGGER_AddExamplesSubDir)
    add_subdirectory(gen/src)
endif()