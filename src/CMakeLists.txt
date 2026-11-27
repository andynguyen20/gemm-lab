add_executable(gemm_lab
    main.cpp
    test.cpp
)

target_include_directories(gemm_lab PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
