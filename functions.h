//
// Created by Macbook Pro on 10/12/2019.
//

#ifndef OP_PROJECT2_FUNCTIONS_H
#define OP_PROJECT2_FUNCTIONS_H

#include "Array.h"
#include "Time.h"
#include "Album.h"
#include <iomanip>
#include "List.h"

int getMinIndex(Array<Album> &, int start);

template <typename T>
void sortArray(Array<T> &array) {
    int minIndex = 0;
    if (array.getSize() == 0) {
        throw "empty array";
    }
    for (int i = 0; i < array.getSize() - 1; ++i) {
        minIndex = getMinIndex(array, i);
        if (minIndex != i) {
        Album tmp(array[i]);
        array[i] = std::move(array[minIndex]);
        array[minIndex] = std::move(tmp);
        }
    }
}

template <typename T>
void printTable(std::ofstream & out, Array<T> &array) {
    if (array.getSize() == 0) {
        throw "empty array";
    }
    out << std::setw(50) << "Album name" << " | " << std::setw(50) << "Singer name" << " | " << std::setw(50) << "janre" << " | " \
    << std::setw(4) << "year" << " | " << std::setw(8) << "time" << " | " << std::setw(15) << "count of songs" << " | " << "songs" << std::endl;
    for (int i = 0; i < array.getSize(); ++i) {
        out << array[i];
    }
}

template <typename T>
void printTable(std::ofstream & out, List<T> &list) {
    out << std::setw(50) << "Janre" << " | " << "count" << std::endl;
    Elem<T> * curr = list.getRoot();
    do {
        out << curr->getValue() << " | " << curr->getCount() << std::endl;
        curr = curr->getNext();
    } while (curr != nullptr);
}

bool isFileEmpty(std::ifstream & );

bool isLineBreak(std::ifstream & );

void skipSpaces(std::ifstream &);

void isEndOfString(std::ifstream &);


#endif //OP_PROJECT2_FUNCTIONS_H
