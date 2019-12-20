//
// Created by Macbook Pro on 10/12/2019.
//
#include "functions.h"
int getMinIndex(Array<Album> & array, int start) {
    if (array.getSize() == 0) {
        throw "empty array";
    }
    if (start < 0 || start >= array.getSize()) {
        throw "bad start index";
    }
    int minIndex = start;
    for (int i = start + 1; i < array.getSize(); ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;

}

bool isFileEmpty(std::ifstream & in) {
    return in.eof();
}

bool isLineBreak(std::ifstream & in) {
    return in.peek() == '\n';
}

void skipSpaces(std::ifstream & in) {
    while (!in.eof()) {
        if (in.peek() == ' ') {
            in.ignore(1);
        } else {
            if (isLineBreak(in)) {
                in.ignore(1);
                return;
            } else {
                throw "expected line break";
            }
        }
    }
    if (in.eof()) {
        throw "end of file reached";
    }
}

void isEndOfString(std::ifstream & in) {
    while (!in.eof()) {
        if (in.peek() == ' ') {
            in.ignore(1);
        } else {
            if (!isLineBreak(in)) {
                throw "";
            }
            return;
        }
    }
    if (in.eof()) {
        throw "end of file reached";
    }
}


