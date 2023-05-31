#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>

class Music {

    private:
        std::string title;
        std::string author;

    public:
        Music();
        Music(std::string title, std::string author);
        std::string getKey();
        void setTitle(std::string title);
        std::string getAuthor();
        void setAuthor(std::string author);

        friend std::ostream& operator<<(std::ostream& os, const Music& music) {
            os << "Title: " << music.title << "\n";
            os << "Artist: " << music.author << "\n";
            return os;
        }
};


#endif