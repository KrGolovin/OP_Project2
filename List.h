//
// Created by Macbook Pro on 10/12/2019.
//

#ifndef OP_PROJECT2_LIST_H
#define OP_PROJECT2_LIST_H
#pragma once
#include "Elem.h"
#include "String.h"
#include "Pair.h"

template <typename T>
class List {
public:
    List();
    void addElem(T &);
    Elem<T>* getRoot();
    Elem<T>* getTail();
    int getSize();
    Elem<T>* search(List<T> & list, T& item) {
        Elem<T> * curr = list.root_;
        while (curr != nullptr) {
            if (curr->getValue() == item){
                return curr;
            } else if (curr->getValue() > item) {
                return curr;
            } else {
                curr = curr->getNext();
            }
        }
        return curr;
    }

private:
    Elem<T>* root_;
    Elem<T>* tail_;
    int size_;
};


template<typename T>
void List<T>::addElem(T & elem) {
    if (size_ == 0) {
        root_ = new Elem<T>(nullptr, nullptr, elem);
        tail_= root_;
        size_++;
    } else {
        Elem<T> * result = search(*this, elem);
        if (result == nullptr) {
            tail_->getNext() = new Elem<T>(nullptr, tail_, elem);
            tail_ = tail_->getNext();
            size_++;
        } else if (result->getValue() == elem) {
            result->getCount()++;
        } else if (result == root_){
            root_->getPrev() = new Elem<T>(root_, nullptr, elem);
            root_ = root_->getPrev();
            size_++;
        } else{
            Elem<T> * tmp = new Elem<T>(result, result->getPrev(), elem);
            result->getPrev()->getNext() = tmp;
            result->getPrev() = tmp;
            size_++;
        }
    }
}

template<typename T>
List<T>::List() {
    root_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

template<typename T>
Elem<T> *List<T>::getRoot() {
    return root_;
}


template<typename T>
Elem<T> *List<T>::getTail() {
    return tail_;
}

template<typename T>
int List<T>::getSize() {
    return size_;
}


#endif //OP_PROJECT2_LIST_H
