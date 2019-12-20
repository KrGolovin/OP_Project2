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
    String buffer(715);
    int start = 0;
    in >> buffer;
    elem.nameOfAlbum_ = String(50);
    start = elem.nameOfAlbum_.read();
    in >> elem.nameOfAlbum_;
    elem.nameOfSinger_ = String(50);
    in >> elem.nameOfSinger_;
    elem.janre_ = String(50);
    in >> elem.janre_;
    in >> elem.year_;
    in >> elem.timeOfAlbum_;
    in >> elem.countOfSongs_;
    in.ignore(1);
    elem.songs_ = static_cast<String*>(operator new[] (elem.countOfSongs_ * sizeof(String)));
    for (int i = 0; i < elem.countOfSongs_; ++i) {
        new (elem.songs_ + i) String(50);
        in >> *(elem.songs_ + i);
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
    delete &nameOfAlbum_;
    delete &nameOfSinger_;
    delete &janre_;
    delete &timeOfAlbum_;
    delete [] songs_;
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

Album &Album::operator=(Album && second) {
    if (&second != this) {
        nameOfAlbum_ = std::move(second.nameOfAlbum_);
        nameOfSinger_ = std::move(second.nameOfSinger_);
        janre_ = std::move(second.janre_);
        year_ = second.year_;
        timeOfAlbum_ = std::move(second.timeOfAlbum_);
        countOfSongs_ = second.countOfSongs_;
        songs_ = second.songs_;
        second.year_ = 2020;
        second.countOfSongs_ = 0;
        second.songs_ = nullptr;
    }
    return *this;
}


