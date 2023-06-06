#ifndef SYSTEM_H
#define SYSTEM_H


#include <string>
#include "Music.h"
#include "Node.h"
#include "List.h"
#include "Playlist.h"


void uniteLists(List<Music> &firstList, List<Playlist> &secondList);
void showAllSongs(List<Music> &musicList);
void findPlaylist(List<Playlist> &playlists);
void populateSystem(List<Music> &musicList);
void populateSystem(List<Playlist> &playlistList);
void createNewPlaylist(List<Playlist> &playlists);
void addNewSong(List<Music> &musicList);
void addNewList(List<Music> &musicList);
void addSongToPlaylist(List<Music> &musicList, List<Playlist> &playlists);
void addPlaylistToPlaylist(List<Playlist> &playlists);
void removeSongFromPlaylist(List<Playlist> &playlists);
void removeSongFromSystem(List<Music> &musicList, List<Playlist> &playlists);
void destructLists(List<Music> &musicList, List<Playlist> &playlists);
void testMenu(List<Music> &musicList);

#endif