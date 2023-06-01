#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Music.h"
#include "Node.h"
#include "Playlist.h"
#include "RemoveSongFromAll.h"
#include "System.h"

using namespace std;

int main() {
    system("clear");
    int menu = 0;
    List<Music> musicList;
    List<Playlist> playlists;

    cout << "WELCOME TO C0DEM4N" << endl;
    while (menu != 10) {
        cout << "Main menu:" << endl;
        cout << "Select an option:" << endl;
        cout << "1 - Add new song to system" << endl;
        cout << "2 - Add new list to a list" << endl;
        cout << "3 - Remove a song from a playlist" << endl;
        cout << "4 - Remove a song from the system" << endl;
        cout << "5 - Show all songs in the system" << endl;
        cout << "6 - Add a song to a playlist" << endl;
        cout << "7 - Destruct lists" << endl;
        cout << "8 - Create a new playlist" << endl;
        cout << "9 - Find a playlist" << endl;
        cout << "10 - Exit program" << endl;
        cin >> menu;
        cin.ignore();

        switch (menu) {
            case 1:
                addNewSong(musicList);
                break;
            case 2:
                addNewList(musicList);
                break;
            case 3:
                removeSongFromPlaylist(playlists);
                break;
            case 4:
                removeSongFromSystem(musicList, playlists);
                break;
            case 5:
                showAllSongs(musicList);
                break;
            case 6:
                addSongToPlaylist(musicList, playlists);
                break;
            case 7:
                destructLists(musicList, playlists);
                break;
            case 8:
                createNewPlaylist(playlists);
                break;
            case 9:
                findPlaylist(playlists);
                break;
            case 10:
                system("clear");
                cout << "Exiting C0DEM4N...." << endl;
                return 0;
            default:
                system("clear");
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}