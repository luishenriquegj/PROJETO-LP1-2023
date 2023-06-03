#ifndef SYSTEM_H
#define SYSTEM_H


#include <string>
#include "Music.h"
#include "Node.h"
#include "List.h"
#include "Playlist.h"

void addNewSong(List<Music>& musicList);
void addNewList(List<Music>& musicList);
void concatenateLists(List<Music>&musicList,List<Music>&secondList);
void removeSongFromPlaylist(List<Playlist>& playlists);
void removeSongFromSystem(List<Music>& musicList, List<Playlist>& playlists);
void showAllSongs(List<Music>& musicList);
void addSongToPlaylist(List<Music>& musicList, List<Playlist>& playlists);
void destructLists(List<Music>& musicList, List<Playlist>& playlists);
void createNewPlaylist(List<Playlist>& playlists);
void findPlaylist(List<Playlist>& playlists);



#endif