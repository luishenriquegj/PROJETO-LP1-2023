#include "RemoveSongFromAll.h"
#include "List.h"
#include "Playlist.h"
#include"Node.h"
#include <string>
#include<iostream>

using namespace std;

int removeSongFromAll(List<Playlist>& playlists,string key) {
    if (playlists.head == nullptr) {
        cout << "ty" << endl;
        return 0;
    }else{
        Node<Playlist>* currentPlaylist = playlists.head;
        Node<Playlist>* previousPlaylist = nullptr;

        while (currentPlaylist != nullptr) {
            currentPlaylist->data.removeSongFromPlaylist(key);
            previousPlaylist = currentPlaylist;
            currentPlaylist = currentPlaylist->next;
        }
    }
    cout << "Song not found: " << key << endl;
    return 0; // song not found
};
