#include "Music.h"

using namespace std;

Music::Music(){
    
}

Music::Music( string title,string author){
    this-> title = title;
    this-> author = author;
}

string Music::getKey(){
    return this-> title = title;
}

void Music::setTitle(string title){
    this->title=title;
}

string Music::getAuthor(){
    return this-> author = author;
}

void Music::setAuthor(string author){
    this->author=author;
}