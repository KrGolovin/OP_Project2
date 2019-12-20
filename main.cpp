#include <iostream>
#include <cstdlib>
#include <fstream>
#include "stdio.h"
#include "Time.h"
#include "Album.h"
#include "Array.h"
#include "functions.h"


using namespace std;

int main() {
    try{
        ifstream in;
        in.open("input.txt");
        if (!in) {
            throw "Input file not open";
        }
        ofstream out;
        out.open("output.txt");
        if (!out) {
            throw "Output file not open";
        }
        int n = 0;
        if (isFileEmpty(in)) {
            throw "File is empty";
        }
        in >> n;
        if (!in) {
            throw "expected number";
        }
        if (n < 0 || n > 100) {
            throw "incorrect size";
        }
        Array<Album> array(n);
        skipSpaces(in);
        for (int  i = 0; i < n; ++i) {
            if (in.eof()) {
                n = i;
                break;
            }
            in >> array[i];
        }
        sortArray(array);
        printTable(out, array);
        List<String> list;
        for (int i = 0; i < n; ++i) {
            list.addElem(array[i].getJanre());
        }
        printTable(out, list);
    } catch (const char * e) {
        std::cerr << e;
        return 0;
    }
    return 0;
}