//
// Created by Macbook Pro on 02/12/2019.
//

#ifndef OP_PROJECT2_ALBUM_H
#define OP_PROJECT2_ALBUM_H

#include "String.h"
#include "Time.h"

class Album {
public:

    Album();
    Album(String, String, String, int, Time, int, String *);
    Album(const Album &);
    Album(Album &&);
    ~Album();
    friend std::ifstream & operator>>(std::ifstream &, Album &);
    friend std::ofstream & operator<<(std::ofstream &, Album &);
    friend bool operator== (const Album &, const Album &);
    friend bool operator!= (const Album &, const Album &);
    friend bool operator> (const Album &, const Album &);
    friend bool operator<= (const Album &, const Album &);
    friend bool operator>= (const Album &, const Album &);
    friend bool operator< (const Album &, const Album &);
    Album& operator=(Album &&);
    Album& operator++();
    Album& operator--();
    String& getJanre();
private:
    String nameOfAlbum_;
    String nameOfSinger_;
    String janre_;
    int year_;
    Time timeOfAlbum_;
    int countOfSongs_;
    String * songs_;
};


#endif //OP_PROJECT2_ALBUM_H
