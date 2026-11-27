add_executable(gemm_lab
    main.cpp
    matrix.cpp
)

target_include_directories(gemm_lab PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
