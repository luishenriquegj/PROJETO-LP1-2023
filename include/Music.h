#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>

class Music {

private:
    std::string titulo;
    std::string autor;

public:
    Music();
    Music(std::string autor,std::string titulo);
    std::string get_titulo(std::string titulo);
    void set_titulo(std::string titulo);
    std::string get_autor(std::string autor);
    void set_autor(std::string autor);

};


#endif