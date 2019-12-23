//
// Created by Macbook Pro on 01/12/2019.
//

#include "String.h"
#include <iomanip>
#include <iostream>
#include "functions.h"

String::String(int size) {
    size_ = size;
    str_ = new char[size + 1];
    for (int i = 0; i < size + 1; ++i) {
        str_[i] = 0;
    }
}

char String::operator[](const int index) {
    if (index < 0 || index >= size_) {
        throw "index out of bounds";
    }
    return str_[index];
}

String::~String() {
    if (str_ != nullptr)
        delete[] str_;
    str_ = nullptr;
}

std::ifstream &operator>>(std::ifstream & in, String & point) {
    //in >> point.str_;
    //point.size_ = std::strlen(point.str_);
    in.getline(point.str_, point.size_, '\n');
    if (point.str_[point.size_] != 0) {
        throw "owerrade";
    }
    return in;
}

std::ofstream &operator<<(std::ofstream & out, String & point) {
    out  << std::setw(50) <<  point.str_;
    return out;
}

String::String() {
    str_ = strdup("Nan");
    size_ = 3;
}

String::String(const String &second ) {
    size_ = second.size_;
    str_ = new char[size_ + 1];
    strcpy(str_, second.str_);
}

String::String(String && second) {
    size_ = second.size_;
    delete [] str_;
    str_ = new char[size_ + 1];
    strcpy(str_, second.str_);
    delete [] second.str_;
    second.str_ = new char[4];
    //second.str_ = strdup("Nan");
    second.size_ = 3;
}

String &String::operator=(const String & second) {
    if (&second != this) {
        size_ = second.size_;
        if (str_ != nullptr) {
            delete[] str_;
        }
        str_ = new char[size_ + 1];
        strcpy(str_, second.str_);
//    second.str_ = strdup("Nan");
//    second.size_ = 3;
    }
    return *this;
}

bool operator==(const String & s1, const String & s2) {
    if (strcmp(s1.str_, s2.str_) == 0) {
        return true;
    }
    return false;
}

bool operator>(const String & s1, const String & s2) {
    if (strcmp(s1.str_, s2.str_) > 0) {
        return true;
    }
    return false;
}
bool operator<(const String & s1, const String & s2) {
    if (strcmp(s1.str_, s2.str_) < 0) {
        return true;
    }
    return false;
}

String &String::operator=(String && second) {
    if (&second != this) {
        size_ = second.size_;
        if (str_ != nullptr) {
            delete[] str_;
        }
        str_ = new char[size_ + 1];
        strcpy(str_, second.str_);
        delete[] second.str_;
        second.str_ = new char[4];
        //second.str_ = strdup("Nan");
        second.size_ = 3;
    }
    return *this;
}

String &String::getValue() {
    return *this;
}

void String::readStr(int &begin, const char *buffer, int size) {
    int end = read(begin, buffer, size);
    if (((end - begin) < 1) || ((end - begin) > 50)) {
        throw "incorrect size of data";
    }
    if (!isName(buffer, begin, end)) {
        throw "bad name";
    }
    size_ = end - begin;
    if (str_ != nullptr) {
        delete[] str_;
    }
    str_ = new char[size_ + 1];
    strncpy(str_, buffer + begin, size_);
    str_[size_] = 0;
    begin = end + 1;
}








