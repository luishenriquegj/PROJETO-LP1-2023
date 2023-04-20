#include "Music.h"

using namespace std;

Music::Music(){}

Music::Music(string autor, string titulo){
    this-> autor = autor;
    this-> titulo = titulo;
}

string Music::get_titulo(string titulo){
    return this-> titulo = titulo;
}

void Music::set_titulo(string titulo){
    this->titulo=titulo;
}

string Music::get_autor(string autor){
    return this-> autor = autor;
}

void Music::set_autor(string autor){
    this->autor=autor;
}