//
// Created by Macbook Pro on 02/12/2019.
//

#ifndef OP_PROJECT2_TIME_H
#define OP_PROJECT2_TIME_H

#include <fstream>
class Time{
public:
    Time();
    Time(const Time &);
    Time(Time &&);
    Time& operator=(Time &&);
    friend std::ifstream & operator>>(std::ifstream &, Time &);
    friend std::ofstream & operator<<(std::ofstream &, Time &);
    friend bool operator== (const Time &c1, const Time &c2);
    friend bool operator!= (const Time &c1, const Time &c2);
    friend bool operator> (const Time &c1, const Time &c2);
    friend bool operator<= (const Time &c1, const Time &c2);
    friend bool operator< (const Time &c1, const Time &c2);
    friend bool operator>= (const Time &c1, const Time &c2);
private:
    int hour_;
    int min_;
    int sec_;
};

#endif //OP_PROJECT2_TIME_H
