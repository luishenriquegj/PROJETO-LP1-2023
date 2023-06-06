#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Music.h"
#include "List.h"
#include "Node.h"
#include "Playlist.h"
#include "RemoveSongFromAll.h"
#include "System.h"

using namespace std;

void populateSystem(List<Music> &musicList){
    Node<Music>* newNode1 = new Node<Music>({ "music 1", "author1" });
    Node<Music>* newNode2 = new Node<Music>({ "music 2", "author2" });
    Node<Music>* newNode3 = new Node<Music>({ "music 3", "author3" });
    Node<Music>* newNode4 = new Node<Music>({ "music 4", "author4" });
    Node<Music>* newNode5 = new Node<Music>({ "music 5", "author5" });
    musicList.add(newNode1);
    musicList.add(newNode2);
    musicList.add(newNode3);
    musicList.add(newNode4);
    musicList.add(newNode5);
    cout<<"system pre-populated with the following musics:"<<endl;
    musicList.print();
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}
void populateSystem(List<Playlist> &playlistList){
    string playlistName1 = "playlist 1";
    string playlistName2 = "playlist 2";
    string playlistName3 = "playlist 3";
    Node<Playlist>* newPlaylist1 = new Node<Playlist>(playlistName1);
    Node<Playlist>* newPlaylist2 = new Node<Playlist>(playlistName2);
    Node<Playlist>* newPlaylist3 = new Node<Playlist>(playlistName3);
    playlistList.add(newPlaylist1);
    playlistList.add(newPlaylist2);
    playlistList.add(newPlaylist3);
    cout<<"system pre-populated with the following playlists:"<<endl;
    playlistList.print();
    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void addNewSong(List<Music> &musicList) {
    system("clear");
    string title, author;
    cout << "Set music title: ";
    getline(cin, title);
    while(title.size() == 0) {
        cout << "A music must have a title" << endl;
        cout << "Set music title: " << endl;
        getline(cin, title);
    }
    cout << "Set music author: ";
    getline(cin, author);
    while(author.size() == 0) {
        cout << "A music must have an author name" << endl;
        cout << "Set music author name: " << endl;
        getline(cin, author);
    }
    Node<Music>* newNode = new Node<Music>({ title, author });

    cout << "\n\033[1m\033[34m" << newNode->data.getKey() << "\033[0m was added successfully." << endl;
    musicList << newNode;

    cout << "Press any key to continue...";
    cin.ignore();
    system("clear");
}

void addNewList(List<Music> &musicList) {
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

void uniteLists(List<Music> &firstList, List<Playlist> & secondList){
    string list1 ="",list2="";
    int selection2 =2;
    system("clear");
    cout<<"avaliable playlists"<<endl;
    secondList.print();
    cout<<"system songs"<<endl;
    firstList.print();
    cout<<"what playlist do you wish to recieve the songs?"<<endl;
    getline(cin,list1);
    while(secondList.findItem(list1)==nullptr){
        system("clear");
        cout<<"avaliable playlists"<<endl;
        secondList.print();
        cout<<"please select a valid option"<<endl;
        cout<<"type a name of a playlist"<<endl;
        getline(cin,list1);
    }
    system("clear");
    cout<<"do you wish to copy all the musics from  the system to the selected playlist?"<<endl;
    cout<<"press 1 to yes and 0 to no"<<endl;
    cin>>selection2;
    while(selection2 != 1 && selection2 != 0){
        system("clear");
        cout<<" pplease select a valid option"<<endl;
        cout<<" press 1 to yes and 0 to no"<<endl;
        cin>>selection2;
    }
    
    switch (selection2) {
        case 1:
            secondList.findItem(list1)->data.data + firstList;
        break;
        default:
            
            while(secondList.findItem(list2)==nullptr){
                system("clear");
                cout<<"avaliable playlists"<<endl;
                secondList.print();
                cout<<"from wich playlist do you wish to get the songs from?"<<endl;
                getline(cin,list2);
                getline(cin,list2);
            }

            secondList.findItem(list1)->data.data + secondList.findItem(list2)->data.data;

        break;
    }
}

void removeSongFromPlaylist(List<Playlist> &playlists) {
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

void removeSongFromSystem(List<Music>& musicList, List<Playlist> &playlists) {
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

void addSongToPlaylist(List<Music> &musicList, List<Playlist> &playlists) {
    system("clear");
    string songName, playlistName;
    
    cout << "What song are you adding? ";
    getline(cin, songName);
    while ( musicList.findItem(songName) == nullptr)
    {
        cout << "unable to find song!!!!"<<endl;
        cout << "try again: "<<endl;
        getline(cin, songName);
    }
    
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

void addPlaylistToPlaylist(List<Playlist> &playlists) {
    string playlistName1, playlistName2;
    cout << "What playlist you want to add to another playlist? ";
    getline(cin, playlistName1);
    cout << "What playlist you want to add to another playlist? ";
    getline(cin, playlistName2);
    Node<Playlist>* playlistNode1 = playlists.findItem(playlistName1);
    Node<Playlist>* playlistNode2 = playlists.findItem(playlistName2);
    if (playlistNode1 != nullptr) {
        playlistNode1->data.addSong(playlistNode2->data);
        cout << "Song added to the playlist successfully." << endl;
        cout<<playlistNode1->data<<endl;
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
    while(playlistName.size() == 0){
        cout << "can't create a playlist without a name: "<< endl;
        cout << "choose a name for it: "<< endl;
        getline(cin, playlistName);
    }
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

void testMenu(List<Music> &list) {
    system("clear");
    cout << "this menu is for tests purposes only"<<endl;
    Node<Music> *testMusic = new Node<Music>({ "crazy train", "ozzy ousbourne" });
    list << testMusic;
    Node<Music> *testMusic2 = new Node<Music>({});
    list >> testMusic2;
   
    cout << "Press any key to continue..."<<endl;
    cout <<  testMusic2->data.getKey() << " " << testMusic2->data.getAuthor()<<endl;
    list.print();
    cin.ignore();
    system("clear");
}

