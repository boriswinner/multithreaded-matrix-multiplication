#define MIN(a, b) ((a) < (b) ? (a) : (b))

#include "matrix.h"
#include <cmath>
#include <thread>


void Matrix::multiply_row(int i, const Matrix &that, vector<int> &result_row) {
    for (int j = 0; j < result_row.size(); ++j) {
        for (int r = 0; r < that.sizerow_; ++r) {
            result_row[j] += this->data_[i][r] * that.data_[r][j];
        }
    }
}

ostream &operator<<(ostream &stream, const Matrix &matrix) {
    for (int i = 0; i < matrix.sizerow_; ++i) {
        stream << "[ ";
        for (int j = 0; j < matrix.sizecol_; ++j) {
            stream << matrix.data_[i][j] << " ";
        }
        stream << "]" << std::endl;
    }
}

Matrix Matrix::multiply(const Matrix &that) {
    vector<vector<DTYPE>> result_data(this->sizerow_, vector<DTYPE>(that.sizecol_, 0));
    for (int i = 0; i < this->sizerow_; ++i) {
        multiply_row(i, that, result_data[i]);
    }
    return Matrix(result_data);
}

Matrix Matrix::multiply_in_threads(const Matrix &that, int threads) {
    vector<vector<DTYPE>> result_data(this->sizerow_, vector<DTYPE>(that.sizecol_, 0));
    std::vector<std::thread> threads_vector(threads);
    for (int i = 0; i < ceil(double(this->sizerow_) / double(threads)); ++i) {
        for (int k = 0; k < MIN(threads, (this->sizerow_ - i * threads)); ++k) {
            threads_vector[k] = std::thread(&Matrix::multiply_row, this, i * threads + k,
                                                          that, std::ref(result_data[i * threads + k]));
        }
        for (int k = 0; k < MIN(threads, (this->sizerow_ - i * threads)); ++k) {
            threads_vector[k].join();
        }
    }
    return Matrix(result_data);
}
