//
// Created by Macbook Pro on 01/12/2019.
//

#ifndef OP_PROJECT2_STRING_H
#define OP_PROJECT2_STRING_H
#pragma once
#include <iostream>
#include <fstream>

class String{
public:
    char operator[](const int);
    friend std::ifstream & operator>>(std::ifstream &, String &);
    friend std::ofstream & operator<<(std::ofstream &, String &);
    String();
    String(int);
    String(const String &);
    String(String &&);
    String & getValue();
    String& operator=(const String &);
    String& operator=(String &&);
    friend bool operator== (const String &, const String &);
    friend bool operator> (const String &, const String &);
    friend bool operator< (const String &, const String &);
    ~String();
    void readStr(int &, const char* , int);

private:
    int size_;
    char* str_;
};



#endif //OP_PROJECT2_STRING_H
