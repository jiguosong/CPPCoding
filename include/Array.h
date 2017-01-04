/*
 * Array.h
 *
 *  Created on: Nov 6, 2016
 *      Author: songjiguo
 */

#ifndef ARRAY_NODE_H_
#define ARRAY_NODE_H_

#include <iostream>
#include <random>
#include <cassert>

using namespace std;

/*
 *
 *    This is the list object
 *
 * */

template<class T>
class Array {
public:

    Array() :
            length(0), lower(0), upper(0) {
    }

    Array(unsigned int array_sz, T __lower, T __upper) :
            length(array_sz), lower(__lower), upper(__upper) {
    }

    ~Array() { }

    vector <T> getUniqueArray();

    vector <T> getRandomArray();

private:
    T lower;
    T upper;
    unsigned int length;
    vector <T> array_;
};

template<class T>
vector <T> Array<T>::getUniqueArray() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <T> dist(lower, upper);

    std::set<int> myset;
    int i = 0;
    while (myset.size() < length) {
        T e = dist(gen);
        assert(e >= lower && e <= upper);
        const bool is_in = myset.find(e) != myset.end();
        if (is_in == false) {
            myset.insert(e);
            array_.push_back(e);
        }
    }

    return array_;
}

template<class T>
vector <T> Array<T>::getRandomArray() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <T> dist(lower, upper);

    for (int i = 0; i < length; ++i) {
        T e = dist(gen);
        assert(e >= lower && e <= upper);
        array_.push_back(e);
    }

    return array_;
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


#endif /* ARRAY_NODE_H_ */
