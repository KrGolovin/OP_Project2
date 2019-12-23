//
// Created by Macbook Pro on 10/12/2019.
//

#ifndef OP_PROJECT2_ELEM_H
#define OP_PROJECT2_ELEM_H
#pragma once
#include "String.h"
#include "Pair.h"
using namespace std;
template <typename T>
class Elem {
public:
    Elem();
    Elem(Elem<T>* ,Elem<T>* ,T);
    Elem<T>* & getNext();
    Elem<T>* & getPrev();
    T& getValue();
    int& getCount();
    bool operator>(Elem<T> & second);
private:
    Elem<T>* next_;
    Elem<T>* prev_;
    T value_;
    int count_;
};

template<typename T>
Elem<T>::Elem() {
    next_ = nullptr;
    prev_ = nullptr;
    count_ = 0;
    value_ = T();
}

template<typename T>
Elem<T>::Elem(Elem * next, Elem * prev, T value) {
    next_ = next;
    prev_ = prev;
    value_ = move(value);
    count_ = 1;
}

template<typename T>
Elem<T>* & Elem<T>::getPrev() {
    return prev_;
}

template<typename T>
Elem<T>* & Elem<T>::getNext() {
    return next_;
}

template<typename T>
T &Elem<T>::getValue() {
    return value_;
}

template<typename T>
int &Elem<T>::getCount() {
    return count_;
}

template<typename T>
bool Elem<T>::operator>(Elem<T> & second) {
    return count_ > second.count_;
}


#endif //OP_PROJECT2_ELEM_H
