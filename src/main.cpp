#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Music.h"
#include "Node.h"
#include "List.h"
 
using namespace std;



int main () {
    system("clear");
    int menu =0;
   
    string auxString;
    Music music,music2;
    Node<Music> n1(music),n2(music2);
    List<Music> musicList;


    while(menu !=6){
        cout<<"WELCOME TO C0DEM4N"<<endl;
        cout<<"Main menu:"<<endl;
        cout<<"select an option:"<<endl;
        cout<<"1 - add new song to a playlist"<<endl;
        cout<<"2 - remove a song from a playlist"<<endl;
        cout<<"3 - remove a song from all playlists"<<endl;
        cout<<"4 - show all songs from a playlist"<<endl;
        cout<<"5 - search a song by title"<<endl;
        cout<<"6 - exit program"<<endl;
        
        cin>> menu;
        cin.ignore();

        if(menu ==1) {
            system("clear");
            cout<<"set music title"<<endl;
            getline(cin,auxString);
            music.setTitle(auxString);
            cout<<"set "<<music.getTitle()<<" author name"<<endl;
            getline(cin,auxString);
            music.setAuthor(auxString);
            cout<<music.getTitle()<<" was added successfuly"<<endl;
            musicList.add(music);
            
            cout << "Press any key to continue...";
            cin.ignore();
            
            system("clear");
            menu = 0;
            
        }

        if(menu ==2) {
            system("clear");
            //TODO: remover musica em uma playlsit
            musicList.removeSong();
            cout << "Press any key to continue...";
            cin.ignore();
            menu = 0;
        }

        if(menu ==3) {
            system("clear");
            //TOO: remover musica de todas as playlsit
            music.setTitle("So far Away");
            cout<<music.getTitle()<<endl;
            cout << "Press any key to continue...";
            cin.ignore();
            system("clear");
            menu = 0;
        }

        if(menu==4) {
            system("clear");
            cout << "exibiting all playlist songs..."<<endl;
            musicList.print();
            cout << "Press any key to continue...";
            cin.ignore();
            menu = 0;
        }

        if(menu==5) {
            system("clear");
            musicList.findSong();
          
            menu=0;
        }

         if(menu==6) {
            system("clear");
            musicList.findSong();
          
            menu=0;
        }

    };
}