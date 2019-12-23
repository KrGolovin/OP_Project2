//
// Created by Macbook Pro on 02/12/2019.
//

#include "Time.h"
#include <iomanip>
#include "functions.h"

Time::Time() {
    hour_ = 0;
    min_ = 0;
    sec_ = 0;
}

std::ifstream &operator>>(std::ifstream &in, Time & t) {
    in >> t.hour_;
    char c = 0;
    in >> c;
    in >> t.min_;
    in >> c;
    in >> t.sec_;
    return in;
}

std::ofstream &operator<<(std::ofstream &out, Time & t) {
    out << t.hour_ << ':' << std::setw(2) << t.min_ << ':' << std::setw(2) << t.sec_;
    return out;
}

Time::Time(const Time & second) : hour_(second.hour_), min_(second.min_), sec_(second.sec_) {}

Time::Time(Time && second): hour_(second.hour_), min_(second.min_), sec_(second.sec_)  {
    second.hour_ = 0;
    second.min_ = 0;
    second.sec_ = 0;

}

Time &Time::operator=(Time && second) {
    hour_ = second.hour_;
    min_ = second.min_;
    sec_ = second.sec_;
    second.hour_ = 0;
    second.min_ = 0;
    second.sec_ = 0;
    return *this;
}

bool operator==(const Time &c1, const Time &c2) {
    return c1.hour_ == c2.hour_ && c1.min_ == c2.min_ && c1.sec_ == c2.sec_;
}

bool operator!=(const Time &c1, const Time &c2) {
    return !(c1 == c2);
}

bool operator>(const Time &c1, const Time &c2) {
    return c1.hour_ > c2.hour_ || (c1.hour_ == c2.hour_ && c1.min_ > c2.min_) || (c1.hour_ == c2.hour_ && c1.min_ == c2.min_ && c1.sec_ > c2.sec_);
}

bool operator<=(const Time &c1, const Time &c2) {
    return !(c1 > c2);
}

bool operator<(const Time &c1, const Time &c2) {
    return !(c1 > c2) && !(c1 == c2);
}

bool operator>=(const Time &c1, const Time &c2) {
    return !(c1 < c2);
}

void Time::readTime(int &begin, const char *buffer, int size) {
    int end = read(begin, buffer, size);
    if (end - begin != 7) {
        throw "incorrect Time";
    }
    if (!isTime(buffer, begin, end)) {
        throw "incorrect Time";
    }
    int hours;
    int min;
    int sec;
    sscanf(buffer + begin, "%d:%d:%d", &hours, &min, &sec);

    if (min > 59 || sec > 59) {
        throw "incorrect Time";
    }
    hour_ = hours;
    min_ = min;
    sec_ = sec;
    begin = end + 1;
}

