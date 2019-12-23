//
// Created by Macbook Pro on 10/12/2019.
//
#include "functions.h"
#include "stdio.h"
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

int read(int start, const char * buffer, int size) {
    int i = 0;
    for(i = start; (i < size) && (buffer[i] != 0) && (buffer[i] != ' '); ++i) {}
    return i;
}

bool isName(const char * buffer, int begin, int end) {
    if (!isupper(buffer[begin])) {
        return false;
    }
    for (int i = begin  + 1; i < end; ++i) {
        if (!isalpha(buffer[i]) && buffer[i] != '_' && buffer[i] != '\'') {
            cout << buffer[i];
            return false;
        }
    }
    return true;
}

int readYear(int & begin, const char *buffer, int size) {
    int end = read(begin, buffer, size);
    if (end - begin != 4) {
        throw "incorrect year";
    }
    int result = 0;
    result = atoi(buffer + begin);
    if (result < 1888 || result > 2020) {
        throw "incorrect year";
    }
    begin = end + 1;
    return result;
}

int readCount(int & begin, const char *buffer, int size) {
    int end = read(begin, buffer, size);
    if (end - begin < 1 || end - begin > 2) {
        throw "incorrect count";
    }
    int result = 0;
    result = atoi(buffer + begin);
    if (result < 0 || result > 10) {
        throw "incorrect count";
    }
    begin = end + 1;
    return result;
}

bool isTime(const char * buffer, int begin, int end) {
    for(int i = begin; i < end; ++i) {
        if (i == begin + 1 || i == begin + 4) {
            if (buffer[i] != ':') {
                return false;
            }
        } else {
            if (!isdigit(buffer[i])) {
                return false;
            }
        }
    }
    return true;
}

void printTable2(std::ofstream & out, List<Pair> &list) {
    out << std::setw(50) << "Janre" << " | " << "count" << std::endl;
    Elem<Pair> * curr = list.getRoot();
    do {
        out << curr->getValue().getValue() << " | " << curr->getValue().getCount() << std::endl;
        curr = curr->getNext();
    } while (curr != nullptr);
}



