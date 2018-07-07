#pragma once
#define DTYPE int

#include <vector>
#include <iostream>


using std::vector;
using std::cout;
using std::ostream;


class Matrix {
public:
    explicit Matrix(const vector<vector<DTYPE>> &data) : data_(data), sizerow_(data.size()),
                                                         sizecol_(data[0].size()) {}

    void multiply_rows(const Matrix &that, vector<vector<int>> &result_data, int start_row, int end_row);

    friend ostream &operator<<(ostream &stream, const Matrix &matrix);

    Matrix multiply(const Matrix &that);

    Matrix multiply_in_threads(const Matrix &that, int threads = 0);

    const vector<vector<DTYPE>>& get_data(){ return data_; }

    int get_sizerow(){ return sizerow_; }

    int get_sizecol(){ return sizecol_; }

protected:
    vector<vector<DTYPE>> data_;
    int sizerow_, sizecol_;
};