#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "List.h"
#include "Music.h"
#include <string>
#include <iostream>

class Playlist {

    private:
        std::string name;
        int size;
        List <Music> data;
    public:
        Playlist(Playlist *playlistToCopy);
        Playlist();
        Playlist(std::string name);
        std::string getKey();
        List<Music> getData();
        void addSong(Node<Music>* Music );
        void addSong(Playlist&playlist);
        void removeSongFromPlaylist(std::string key);
        void removeSongFromPlaylist(Playlist &playlist);
        friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist) {
            os << "Playlist Name: " << playlist.name << "\n";
            Node<Music>* current = playlist.data.head;
            os << "musics:" << "\n";
            while (current != nullptr) {
                os << current->data.getKey() << "\n";
                current = current->next;
            }
            return os;
        }

        Playlist operator+(const Playlist& secondPlaylist) {
        Playlist result = *this;  // Create a copy of the current playlist
        Node<Music>* current = secondPlaylist.data.head;

        // Traverse the second playlist
        while (current != nullptr) {
            bool keyExists = false;
            Node<Music>* thisCurrent = result.data.head;

            // Check if the key already exists in the current playlist
            while (thisCurrent != nullptr) {
                if (thisCurrent->data.getKey() == current->data.getKey()) {
                    keyExists = true;
                    break;
                }
                thisCurrent = thisCurrent->next;
            }

            // Add the music to the current playlist only if the key doesn't exist
            if (!keyExists) {
                result.addSong(current);
            }

            current = current->next;
        }

        return result;
    }
};



#endif