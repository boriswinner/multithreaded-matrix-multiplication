#define MIN(a, b) ((a) < (b) ? (a) : (b))

#include "matrix.h"
#include <cmath>
#include <thread>

//end row is real end + 1
void Matrix::multiply_rows(const Matrix &that, vector<vector<int>> &result_data, int start_row, int end_row) {
    for (int i = start_row; i < MIN(result_data.size(),end_row); ++i){
        for (int j = 0; j < result_data[i].size(); ++j) {
            for (int r = 0; r < that.sizerow_; ++r) {
                result_data[i][j] += this->data_[i][r] * that.data_[r][j];
            }
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
        multiply_rows(that, result_data, 0, this->sizerow_);
    return Matrix(result_data);
}

Matrix Matrix::multiply_in_threads(const Matrix &that, int threads) {
    vector<vector<DTYPE>> result_data(this->sizerow_, vector<DTYPE>(that.sizecol_, 0));
    std::vector<std::thread> threads_vector(threads);
    int rows_in_thread = int(ceil(double(this->sizerow_) / double(threads)));
    for (int i = 0; i < threads; ++i) {
        threads_vector[i] = std::thread(&Matrix::multiply_rows, this, that, std::ref(result_data), i*rows_in_thread,(i+1)*rows_in_thread);
    }
    for (int k = 0; k < threads; ++k) {
        threads_vector[k].join();
    }
    return Matrix(result_data);
}
