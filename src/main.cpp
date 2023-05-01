#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Music.h"
#include "Node.h"
#include "Playlist.h"
 
using namespace std;



int main () {
    system("clear");
    int menu =0;
    string auxString1,auxString2;
    Music music;
    List<Music> musicList;
    Playlist p1 ;
    List<Playlist> playlists;

    while(menu !=9){
        cout<<"WELCOME TO C0DEM4N"<<endl;
        cout<<"Main menu:"<<endl;
        cout<<"select an option:"<<endl;
        cout<<"1 - add new song to system"<<endl;
        cout<<"2 - remove a song on system"<<endl;
        cout<<"3 - remove a song on system"<<endl;
        cout<<"4 - show all songs on system"<<endl;
        cout<<"5 - add a song to a playlsit"<<endl;
        cout<<"6 - destruct list"<<endl;
        cout<<"7 - create a new playlist"<<endl;
        cout<<"8 - find a playlist"<<endl;
        cout<<"9 - exit program"<<endl;
        cin>> menu;
        cin.ignore();

        if(menu ==1) {
            system("clear");
            cout<<"set music title"<<endl;
            getline(cin,auxString1);
            cout<<"set music author"<<endl;
            getline(cin,auxString2);
            Node<Music>* newNode = new Node<Music>({auxString1,auxString2});
            
            cout<<"\n"<<"\033[1m\033[34m" <<newNode->data.getKey()<< "\033[0m"<< " was added successfuly"<<endl;
            musicList.add(newNode);
            
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
            cout<<"what song are you adding?"<<endl;
            Node <Music>* musicAux = musicList.findItem();
            cout<<"what playlist are you adding "<<musicAux->data.getAuthor()<<" to?"<<endl;
            // Node <Playlist>* playlistPrint = playlists.findItem();
            // cout<<playlistPrint->data.getKey()<<endl;
            // cout<<playlistPrint<<endl;
            menu=0;
        }
        
        if(menu==6) {
            system("clear");
            musicList.~List();
            cout<<"deletei tudo"<<endl;
            cout << "Press any key to continue...";
            cin.ignore();

          
            menu=0;
        }
        
        if(menu ==7) {
            system("clear");
            cout<<"set playlist name: "<<endl;
            getline(cin,auxString1);
            Node<Playlist>* newNode = new Node<Playlist>(auxString1);
            cout<<newNode->data.getKey()<<endl;
            playlists.add(newNode);
            cout << "Press any key to continue...";
            cin.ignore();
            
            system("clear");
            menu = 0;
        };
        
        if(menu ==8) {
            system("clear");
            //TOO: Achar musica ou playlist
            cout<<playlists.print()<<endl;
            cout << "Press any key to continue...";
            cin.ignore();
            system("clear");
            menu = 0;
        }
        
        if(menu==9) {
            system("clear");
            cout<< "Exiting C0DEM4N...."<<endl;
            return 0;          
        }
    }

    return 0;
}