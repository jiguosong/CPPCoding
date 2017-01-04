/*
 * matrix.h
 *
 *  Created on: Dec 17, 2016
 *      Author: songjiguo
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <cassert>
#include <random>

template<class T>
class Matrix {
public:
    Matrix();

    Matrix(const unsigned int row, const unsigned int column, int lower,
           int upper);

    ~Matrix() { };

    std::vector <std::vector<T>> getRandomMatrix();

    std::vector <std::vector<T>> getRowSortedMatrix();

    std::vector <std::vector<T>> getRowSortedIncreasingMatrix();

private:
    unsigned int row_;
    unsigned int column_;
    int lower_, upper_;
    std::vector <std::vector<T>> *ptrMatrix_;
};

template<typename T>
Matrix<T>::Matrix() :
        row_(0), column_(0), lower_(0), upper_(0), ptrMatrix_(nullptr) {
}

template<typename T>
Matrix<T>::Matrix(const unsigned int row, const unsigned int column, int lower,
                  int upper) :
        row_(row), column_(column), lower_(lower), upper_(upper), ptrMatrix_(
        nullptr) {
    assert(row > 0 && column > 0);
    ptrMatrix_ = new std::vector <std::vector<T>>(row,
                                                  std::vector<T>(column, 0));
}

template<typename T>
std::vector <std::vector<T>> Matrix<T>::getRandomMatrix() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <T> dist(lower_, upper_);

    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < column_; ++j) {
            (*ptrMatrix_)[i][j] = dist(gen);
        }
    }
    return *ptrMatrix_;
}

template<typename T>
std::vector <std::vector<T>> Matrix<T>::getRowSortedMatrix() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <T> dist(lower_, upper_);

    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < column_; ++j) {
            (*ptrMatrix_)[i][j] = dist(gen);
        }
        std::sort((*ptrMatrix_)[i].begin(), (*ptrMatrix_)[i].end()); // sort the row
    }
    return *ptrMatrix_;
}

template<typename T>
std::vector <std::vector<T>> Matrix<T>::getRowSortedIncreasingMatrix() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < row_; ++i) {
        int range = upper_ - lower_;
        int perrow_range = range / row_;
        std::uniform_int_distribution <T> dist(lower_ + i * perrow_range,
                                               lower_ + (i + 1) * perrow_range);
        for (int j = 0; j < column_; ++j) {
            (*ptrMatrix_)[i][j] = dist(gen);
        }
        std::sort((*ptrMatrix_)[i].begin(), (*ptrMatrix_)[i].end()); // sort the row
    }
    return *ptrMatrix_;
}


// https://www.sitmo.com/?p=378
template<int d1, int d2 = 1, int d3 = 1, int d4 = 1>
class TensorIndex {
public:
    enum {
        SIZE = d1 * d2 * d3 * d4
    };
    enum {
        LEN1 = d1
    };
    enum {
        LEN2 = d2
    };
    enum {
        LEN3 = d3
    };
    enum {
        LEN4 = d4
    };

    static int indexOf(const int i) {
        return i;
    }

    static int indexOf(const int i, const int j) {
        return j * d1 + i;
    }

    static int indexOf(const int i, const int j, const int k) {
        return (k * d2 + j) * d1 + i;
    }

    static int indexOf(const int i, const int j, const int k, const int l) {
        return ((l * d3 + k) * d2 + j) * d1 + i;
    }
};


#endif /* MATRIX_H_ */
