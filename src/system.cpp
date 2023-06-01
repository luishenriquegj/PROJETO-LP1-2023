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

void addNewSong(List<Music>& musicList) {
    system("clear");
    string title, author;
    cout << "Set music title: ";
    getline(cin, title);
    cout << "Set music author: ";
    getline(cin, author);
    Node<Music>* newNode = new Node<Music>({ title, author });

    cout << "\n\033[1m\033[34m" << newNode->data.getKey() << "\033[0m was added successfully." << endl;
    musicList.add(newNode);

    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void addNewList(List<Music>& musicList) {
    system("clear");
    string title, author;
    List<Music>* newList = new List<Music>();
    int submenu = 1;
    while (submenu == 1) {
        system("clear");
        cout << "Set music title: ";
        getline(cin, title);
        cout << "Set music author: ";
        getline(cin, author);
        Node<Music>* auxNode = new Node<Music>({ title, author });
        newList->add(auxNode);

        cout << "Press 0 to exit or 1 to continue.." << endl;
        cin >> submenu;
        cin.ignore();
        if (submenu != 0) {
            submenu = 1;
        }
        system("clear");
    }

    musicList.add(newList);
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void removeSongFromPlaylist(List<Playlist>& playlists) {
    system("clear");
    string playlistName, songName;
    cout << "Which playlist are you looking for? ";
    getline(cin, playlistName);
    cout << "Which song do you want to remove? ";
    getline(cin, songName);
    playlists.findItem(playlistName)->data.removeSongFromPlaylist(songName);
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void removeSongFromSystem(List<Music>& musicList, List<Playlist>& playlists) {
    system("clear");
    string songName;
    cout << "What song do you wish to remove from the database? ";
    getline(cin, songName);
    musicList.removeItem(songName);
    removeSongFromAll(playlists, songName);
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void showAllSongs(List<Music>& musicList) {
    system("clear");
    cout << "Exhibiting all playlist songs..." << endl;
    musicList.print();
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void addSongToPlaylist(List<Music>& musicList, List<Playlist>& playlists) {
    system("clear");
    string songName, playlistName;
    
    cout << "What song are you adding? ";
    getline(cin, songName);
    
    string title = musicList.findItem(songName)->data.getKey();
    string author = musicList.findItem(songName)->data.getAuthor();
    Node<Music>* musicAux = new Node<Music>({ title, author });
    
    cout << "What playlist are you adding " << musicAux->data.getAuthor() << " to? ";
    getline(cin, playlistName);

    Node<Playlist>* playlistNode = playlists.findItem(playlistName);

    if (playlistNode != nullptr) {
        playlistNode->data.addSong(musicAux);
        cout << "Song added to the playlist successfully." << endl;
        cout << "Press any key to continue...";
        cin.ignore();
    } else {
        cout << "Playlist not found. Song couldn't be added." << endl;
        cout << "Press any key to continue...";
        cin.ignore();
    }
    system("clear");
}

void destructLists(List<Music>& musicList, List<Playlist>& playlists) {
    system("clear");
    musicList.~List();
    playlists.~List();
    cout << "All lists deleted." << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void createNewPlaylist(List<Playlist>& playlists) {
    system("clear");
    string playlistName;
    cout << "Set playlist name: ";
    getline(cin, playlistName);
    Node<Playlist>* newPlaylist = new Node<Playlist>(playlistName);
    playlists.add(newPlaylist);
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void findPlaylist(List<Playlist>& playlists) {
    system("clear");
    playlists.print();
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}