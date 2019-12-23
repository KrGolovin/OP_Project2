//
// Created by Macbook Pro on 10/12/2019.
//

#ifndef OP_PROJECT2_ARRAY_H
#define OP_PROJECT2_ARRAY_H
#pragma once
template <typename T>
class Array {
public:
    explicit Array(int);
    T& operator[] (int);
    int getSize();
private:
    T* arr_;
    int size_;
};

template<typename T>
T &Array<T>::operator[](const int index) {
    if (index < 0 || index >= size_) {
        throw "index out of bounds";
    }
    return arr_[index];
}

template<typename T>
Array<T>::Array(int size) {
    if (size < 0) {
        throw "bad size";
    }
    size_ = size;
    arr_ = new T[size];
}

template<typename T>
int Array<T>::getSize() {
    return size_;
}


#endif //OP_PROJECT2_ARRAY_H
