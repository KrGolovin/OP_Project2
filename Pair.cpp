//
// Created by Macbook Pro on 22/12/2019.
//

#include "Pair.h"

int Pair::getCount() {
    return count_;
}

String &Pair::getValue() {
    return value_;
}

bool Pair::operator>(Pair & second) {
    return count_ > second.count_;
}

Pair::Pair(int count, const String& value): count_(count), value_(value){}

bool Pair::operator==(Pair & second) {
    return value_ == second.value_;
}

Pair::Pair(Pair && second): count_(second.count_), value_(std::move(second.value_)) {}

Pair::Pair(const Pair& second): count_(second.count_), value_(second.value_) {}

Pair &Pair::operator=(Pair && second) {
    value_ = std::move(second.value_);
    count_ = second.count_;

    return *this;
}
