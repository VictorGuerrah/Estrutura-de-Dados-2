#include <stdlib.h>
#include "registro.h"

using namespace std;

//contrutor
registro::registro(){
    //ctor
}

//destrutor
registro::~registro(){
    //dtor
}

void registro::setId(int id){
    this->id = id;
}

int registro::getId(){
    return id;
}

void registro::setUser(string user){
    this->user = user;
}

string registro::getUser(){
    return user;
}

void registro::setRating(int rating){
    this->rating = rating;
}

int registro::getRating(){
    return rating;
}

