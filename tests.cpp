#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <vector>
#include "matrix.h"

using std::vector;
using std::cout;
using std::ostream;

TEST_CASE("Single-Threaded Multiply") {
    SECTION("Create matrix") {
        vector<vector<DTYPE>> a_data = {{5, 3, 1},
                                        {2, 3, 6}};
        Matrix a(a_data);
        REQUIRE(a.get_data() == a_data);
        REQUIRE(a.get_sizecol() == 3);
        REQUIRE(a.get_sizerow() == 2);
        Matrix b({{5, 3, 1},
                  {2, 3, 6}});
        Matrix c({{0, 1}});
        Matrix d({{0},
                  {0}});
    }

    SECTION("Multiply matrix") {
        vector<vector<DTYPE>> a_data = {{5, 3, 1},
                                        {2, 3, 6}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{3, 1},
                                        {5, 2},
                                        {7, 3}
        };
        Matrix b(b_data);
        Matrix c = a.multiply(b);
        vector<vector<DTYPE>> res = {{37, 14},
                                     {63, 26}};
        REQUIRE(c.get_data() == res);
    }

    SECTION("Multiply matrix 2") {
        vector<vector<DTYPE>> a_data = {{1, 3},
                                        {1, 2}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{1, 2, 1},
                                        {3, 1, 0}};
        Matrix b(b_data);

        vector<vector<DTYPE>> expected_c_data = {{10, 5, 1},
                                                 {7,  4, 1}};
        Matrix expected_c(expected_c_data);

        Matrix result = a.multiply(b);
        REQUIRE(result.get_data() == expected_c.get_data());
    }

    SECTION("Big matrix") {
        vector<vector<DTYPE>> a_data(1000, vector<DTYPE>(1000, 1));
        vector<vector<DTYPE>> b_data(1000, vector<DTYPE>(1000, 1));
        vector<vector<DTYPE>> expected_c_data(1000, vector<DTYPE>(1000, 1000));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix expected_c(expected_c_data);
        Matrix c = a.multiply(b);
        REQUIRE(c.get_data() == expected_c.get_data());
    }
}

TEST_CASE("Dual-Threaded Multiply") {
    SECTION("Multiply matrix") {
        vector<vector<DTYPE>> a_data = {{5, 3, 1},
                                        {2, 3, 6}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{3, 1},
                                        {5, 2},
                                        {7, 3}
        };
        Matrix b(b_data);
        Matrix c = a.multiply_in_threads(b,2);
        vector<vector<DTYPE>> res = {{37, 14},
                                     {63, 26}};
        REQUIRE(c.get_data() == res);
    }

    SECTION("Multiply matrix 2") {
        vector<vector<DTYPE>> a_data = {{1, 3},
                                        {1, 2}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{1, 2, 1},
                                        {3, 1, 0}};
        Matrix b(b_data);

        vector<vector<DTYPE>> expected_c_data = {{10, 5, 1},
                                                 {7,  4, 1}};
        Matrix expected_c(expected_c_data);

        Matrix result = a.multiply_in_threads(b,2);
        REQUIRE(result.get_data() == expected_c.get_data());
    }

    SECTION("Big matrix") {
        vector<vector<DTYPE>> a_data(1000, vector<DTYPE>(1000, 1));
        vector<vector<DTYPE>> b_data(1000, vector<DTYPE>(1000, 1));
        vector<vector<DTYPE>> expected_c_data(1000, vector<DTYPE>(1000, 1000));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix expected_c(expected_c_data);
        Matrix c = a.multiply_in_threads(b,2);
        REQUIRE(c.get_data() == expected_c.get_data());
    }
}

TEST_CASE("Quad-Threaded Multiply") {
    SECTION("Multiply matrix") {
        vector<vector<DTYPE>> a_data = {{5, 3, 1},
                                        {2, 3, 6}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{3, 1},
                                        {5, 2},
                                        {7, 3}
        };
        Matrix b(b_data);
        Matrix c = a.multiply_in_threads(b,4);
        vector<vector<DTYPE>> res = {{37, 14},
                                     {63, 26}};
        REQUIRE(c.get_data() == res);
    }

    SECTION("Multiply matrix 2") {
        vector<vector<DTYPE>> a_data = {{1, 3},
                                        {1, 2}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{1, 2, 1},
                                        {3, 1, 0}};
        Matrix b(b_data);

        vector<vector<DTYPE>> expected_c_data = {{10, 5, 1},
                                                 {7,  4, 1}};
        Matrix expected_c(expected_c_data);

        Matrix result = a.multiply_in_threads(b,4);
        REQUIRE(result.get_data() == expected_c.get_data());
    }

    SECTION("Big matrix") {
        vector<vector<DTYPE>> a_data(1000, vector<DTYPE>(1000, 1));
        vector<vector<DTYPE>> b_data(1000, vector<DTYPE>(1000, 1));
        vector<vector<DTYPE>> expected_c_data(1000, vector<DTYPE>(1000, 1000));
        Matrix a(a_data);
        Matrix b(b_data);
        Matrix expected_c(expected_c_data);
        Matrix c = a.multiply_in_threads(b,4);
        REQUIRE(c.get_data() == expected_c.get_data());
    }
}

TEST_CASE("10-Threaded Multiply") {
    SECTION("Multiply matrix") {
        vector<vector<DTYPE>> a_data = {{5, 3, 1},
                                        {2, 3, 6}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{3, 1},
                                        {5, 2},
                                        {7, 3}
        };
        Matrix b(b_data);
        Matrix c = a.multiply_in_threads(b,10);
        vector<vector<DTYPE>> res = {{37, 14},
                                     {63, 26}};
        REQUIRE(c.get_data() == res);
    }

    SECTION("Multiply matrix 2") {
        vector<vector<DTYPE>> a_data = {{1, 3},
                                        {1, 2}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{1, 2, 1},
                                        {3, 1, 0}};
        Matrix b(b_data);

        vector<vector<DTYPE>> expected_c_data = {{10, 5, 1},
                                                 {7,  4, 1}};
        Matrix expected_c(expected_c_data);

        Matrix result = a.multiply_in_threads(b,10);
        REQUIRE(result.get_data() == expected_c.get_data());
    }
}

TEST_CASE("Comparison") {
    SECTION("Not equal with unequal dimension") {
        vector<vector<DTYPE>> a_data = {{1, 3},
                                        {1, 2}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{1, 3},
                                        {1, 2},
                                        {1, 5}};
        Matrix b(b_data);
        REQUIRE(!(a.get_data() == b.get_data()));
    }

    SECTION("Not equal") {
        vector<vector<DTYPE>> a_data = {{1, 3},
                                        {1, 2}};
        Matrix a(a_data);
        vector<vector<DTYPE>> b_data = {{1, 4},
                                        {1, 2}};
        Matrix b(b_data);
        REQUIRE(!(a.get_data() == b.get_data()));
    }
}

