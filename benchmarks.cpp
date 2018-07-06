#define BENCHPRESS_CONFIG_MAIN
#include "benchpress/benchpress.hpp"
#include "matrix.h"


BENCHMARK("single-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        Matrix a({{5, 3, 1},
                  {2, 3, 6}});
        Matrix b({{3, 1},
                  {5, 2},
                  {7, 3}});
        Matrix c = a.multiply(b);
    }
})

BENCHMARK("dual-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        Matrix a({{5, 3, 1},
                  {2, 3, 6}});
        Matrix b({{3, 1},
                  {5, 2},
                  {7, 3}});
        Matrix c = a.multiply_in_threads(b, 2);
    }
})

BENCHMARK("Big single-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        vector<vector<DTYPE>> a_data(50, vector<DTYPE>(50, 1));
        vector<vector<DTYPE>> b_data(50, vector<DTYPE>(50, 1));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix c = a.multiply(b);
    }
})

BENCHMARK("Big dual-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        vector<vector<DTYPE>> a_data(50, vector<DTYPE>(50, 1));
        vector<vector<DTYPE>> b_data(50, vector<DTYPE>(50, 1));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix c = a.multiply_in_threads(b, 2);
    }
})

BENCHMARK("Huge single-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        vector<vector<DTYPE>> a_data(100, vector<DTYPE>(100, 1));
        vector<vector<DTYPE>> b_data(100, vector<DTYPE>(100, 1));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix c = a.multiply(b);
    }
})

BENCHMARK("Huge dual-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        vector<vector<DTYPE>> a_data(100, vector<DTYPE>(100, 1));
        vector<vector<DTYPE>> b_data(100, vector<DTYPE>(100, 1));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix c = a.multiply_in_threads(b, 2);
    }
})

BENCHMARK("Huge quad-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        vector<vector<DTYPE>> a_data(100, vector<DTYPE>(100, 1));
        vector<vector<DTYPE>> b_data(100, vector<DTYPE>(100, 1));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix c = a.multiply_in_threads(b, 4);
    }
})

BENCHMARK("Huge octa-threaded multiplication", [](benchpress::context* ctx) {
    for (size_t i = 0; i < ctx->num_iterations(); ++i) {
        vector<vector<DTYPE>> a_data(100, vector<DTYPE>(100, 1));
        vector<vector<DTYPE>> b_data(100, vector<DTYPE>(100, 1));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix c = a.multiply_in_threads(b, 8);
    }
})