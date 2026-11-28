add_executable(bench_gemm
    bench_gemm.cpp
    ../src/matrix.cpp
    ../src/gemm.cpp
)

target_include_directories(bench_gemm PRIVATE ../include)