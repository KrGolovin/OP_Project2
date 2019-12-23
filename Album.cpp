//
// Created by Macbook Pro on 02/12/2019.
//

#include "Album.h"
#include <iomanip>
#include "functions.h"

Album::Album() {
    nameOfAlbum_ = String();
    nameOfSinger_ = String();
    janre_ = String();
    year_ = 2020;
    timeOfAlbum_ = Time();
    countOfSongs_ = 0;
    songs_ = nullptr;
}

Album::Album(const Album & second) {
    nameOfAlbum_ = String(second.nameOfAlbum_);
    nameOfSinger_ = String(second.nameOfSinger_);
    janre_ = String(second.janre_);
    year_ = second.year_;
    timeOfAlbum_ = Time(second.timeOfAlbum_);
    countOfSongs_ = second.countOfSongs_;
    songs_ = static_cast<String*>(operator new[] (countOfSongs_ * sizeof(String)));
    for (int i = 0; i < countOfSongs_; ++i) {
        new (songs_ + i) String(second.songs_[i]);
    }
}

std::ifstream &operator>>(std::ifstream & in, Album & elem) {
    char buffer[715];
    for (int i = 0; i < 715; ++i) {
        buffer[i] = 0;
    }
    int start = 0;
    in.getline(buffer, 715, '\n');
    elem.nameOfAlbum_ = String(50);
    elem.nameOfAlbum_.readStr(start, buffer, 715);
    elem.nameOfSinger_ = String(50);
    elem.nameOfSinger_.readStr(start, buffer, 715);
    elem.janre_ = String(50);
    elem.janre_.readStr(start, buffer, 715);
    elem.year_ = readYear(start, buffer, 715);
    elem.timeOfAlbum_.readTime(start, buffer, 715);
    elem.countOfSongs_ = readCount(start, buffer, 715);
    elem.songs_ = static_cast<String*>(operator new[] (elem.countOfSongs_ * sizeof(String)));
    for (int i = 0; i < elem.countOfSongs_; ++i) {
        new (elem.songs_ + i) String(50);
        (elem.songs_ + i)->readStr(start, buffer, 715);
    }
    return in;
}

std::ofstream &operator<<(std::ofstream & out, Album & elem) {
    out << elem.nameOfAlbum_ << " | ";
    out << elem.nameOfSinger_ << " | ";
    out << elem.janre_ << " | ";
    out << elem.year_ << " | ";
    out << elem.timeOfAlbum_ << " | ";
    out << std::setw(15) << elem.countOfSongs_ << " | ";
    for (int i = 0; i < elem.countOfSongs_; ++i) {
        out << elem.songs_[i] << ' ';
    }
    out << std::endl;
    return out;
}

Album::Album(String nameOfAlbum, String nameOfSinger, String janre, int year, Time timeOfAlbum, int countOfsongs, String * songs) \
: nameOfAlbum_(nameOfAlbum), nameOfSinger_(nameOfSinger), janre_(janre), year_(year), timeOfAlbum_(timeOfAlbum), countOfSongs_(countOfsongs)
{
    songs_ = static_cast<String*>(operator new[] (countOfSongs_ * sizeof(String)));
    for (int i = 0; i < countOfSongs_; ++i) {
        new (songs_ + i) String(songs[i]);
    }
}

Album::Album(Album && second):  nameOfAlbum_(std::move(second.nameOfAlbum_)), nameOfSinger_(std::move(second.nameOfSinger_)),\
janre_(std::move(second.janre_)), year_(second.year_), timeOfAlbum_(std::move(second.timeOfAlbum_)),\
countOfSongs_(second.countOfSongs_), songs_(second.songs_){
    second.year_ = 2020;
    second.countOfSongs_ = 0;
    second.songs_ = nullptr;
}

Album::~Album() {
    nameOfAlbum_.~String();
    nameOfSinger_.~String();
    janre_.~String();
    timeOfAlbum_.~Time();
    for (int i = 0; i < countOfSongs_; i++)
    {
        songs_[i].~String();
    }
    operator delete[] (songs_);
}

bool operator==(const Album &c1, const Album &c2) {
    return c1.timeOfAlbum_ == c2.timeOfAlbum_;
}

bool operator!=(const Album &c1, const Album &c2) {
    return c1.timeOfAlbum_ != c2.timeOfAlbum_;
}

bool operator>(const Album &c1, const Album &c2) {
    return c1.timeOfAlbum_ > c2.timeOfAlbum_;
}

bool operator<=(const Album &c1, const Album &c2) {
    return !(c1 > c2);
}

bool operator<(const Album &c1, const Album &c2) {
    return c1.timeOfAlbum_ < c2.timeOfAlbum_;
}

bool operator>=(const Album &c1, const Album &c2) {
    return !(c1 < c2);
}

Album &Album::operator++() {
    year_++;
    if (year_ > 2020) {
        throw "year exception";
    }
    return *this;
}

Album &Album::operator--() {
    year_--;
    if (year_ < 1888) {
        throw "year exception";
    }
    return *this;
}

String &Album::getJanre() {
    return janre_;
}

Album &Album::operator=(const Album & second) {
    if (&second != this) {
        nameOfAlbum_.~String();
        nameOfSinger_.~String();
        janre_.~String();
        timeOfAlbum_.~Time();
        for (int i = 0; i < countOfSongs_; i++)
        {
            songs_[i].~String();
        }
        operator delete[] (songs_);
        nameOfAlbum_ = second.nameOfAlbum_;
        nameOfSinger_ = second.nameOfSinger_;
        janre_ = second.janre_;
        year_ = second.year_;
        timeOfAlbum_ = Time(second.timeOfAlbum_);
        countOfSongs_ = second.countOfSongs_;
        songs_ = static_cast<String*>(operator new[] (countOfSongs_ * sizeof(String)));
        for (int i = 0; i < countOfSongs_; ++i) {
            new (songs_ + i) String(second.songs_[i]);
        }
    }
    return *this;
}


