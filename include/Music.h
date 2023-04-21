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
        std::string get_titulo();
        void set_titulo(std::string titulo);
        std::string get_autor();
        void set_autor(std::string autor);

        friend std::ostream& operator<<(std::ostream& os, const Music& music) {
        os << "Title: " << music.titulo << "\n";
        os << "Artist: " << music.autor << "\n";
        return os;
    }
};


#endif