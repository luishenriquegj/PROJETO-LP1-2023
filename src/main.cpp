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
    populateSystem(musicList);
    populateSystem(playlists);
    

    cout << "WELCOME TO C0DEM4N" << endl;
    while (menu != 15) {
        cout << "Main menu:" << endl;
        cout << "Select an option:" << endl;
        cout << "1 - Add new song to Main List" << endl;
        cout << "2 - empty menu" << endl;
        cout << "3 - Concatenate lists" << endl;
        cout << "4 - Add new list to a list" << endl;
        cout << "5 - Remove a song from a playlist" << endl;
        cout << "6 - Remove a song from the system" << endl;
        cout << "7 - Show all songs in the system" << endl;
        cout << "8 - Add a song to a playlist" << endl;
        cout << "9 - Destruct lists" << endl;
        cout << "10 - Create a new playlist" << endl;
        cout << "11 - Find a playlist" << endl;
        cout << "12 - add playlist to playlist" << endl;
        cout << "13 - test menu" << endl;
        cout << "14 - Exit program" << endl;
        cin >> menu;
        cin.ignore();
        List<Music> testList = playlists.findItem("playlist 1")->data.getData();
        switch (menu) {
            case 1:
                addNewSong(musicList);
                break; 
            case 2:
                break;
            case 3:
                uniteLists(musicList,testList);
                break;
            case 4:
                addNewList(musicList);
                break;
            case 5:
                removeSongFromPlaylist(playlists);
                break;
            case 6:
                removeSongFromSystem(musicList, playlists);
                break;
            case 7:
                showAllSongs(musicList);
                break;
            case 8:
                addSongToPlaylist(musicList, playlists);
                break;
            case 9:
                destructLists(musicList, playlists);
                break;
            case 10:
                createNewPlaylist(playlists);
                break;
            case 11:
                findPlaylist(playlists);
                break;
            case 12:
                 addPlaylistToPlaylist(playlists);
                break;
            case 13:
                testMenu(musicList);
                break;
            case 14:
                system("clear");
                cout << "Exiting C0DEM4N...." << endl;
                return 0;
                break;
            default:
                system("clear");
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}