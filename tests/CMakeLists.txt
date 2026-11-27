add_executable(test_gemm
    test_gemm.cpp
    ../src/matrix.cpp
    ../src/gemm.cpp
)

target_include_directories(test_gemm PRIVATE ../include)

add_test(NAME gemm_correctness COMMAND test_gemm)