#include "Playlist.h"
#include "List.h"
#include <string>
#include "Music.h"

using namespace std;
 
Playlist::Playlist(List <Music *> musics,string name){
    this->name = name;
    this->musics = musics;
}
Playlist::Playlist(){
    this->name = "";
}

