//
// Created by Macbook Pro on 22/12/2019.
//

#ifndef OP_PROJECT2_PAIR_H
#define OP_PROJECT2_PAIR_H
#pragma once
#include "String.h"

class Pair {
public:
    Pair() = default;
    Pair(int, const String&);
    Pair(Pair &&);
    Pair(const Pair &);
    int getCount();
    String& getValue();
    bool operator>(Pair &);
    bool operator==(Pair &);
    Pair &operator=(Pair &&);
private:
    int count_;
    String value_;
};


#endif //OP_PROJECT2_PAIR_H
