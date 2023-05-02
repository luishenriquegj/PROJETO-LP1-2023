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
    string auxString1,auxString2,auxString3;
    Music music;
    List<Music> musicList;
    Playlist p1 ;
    List<Playlist> playlists;

    cout<<"WELCOME TO C0DEM4N"<<endl;
    while(menu !=9){
        cout<<"Main menu:"<<endl;
        cout<<"select an option:"<<endl;
        cout<<"1 - add new song to system"<<endl;
        cout<<"2 - remove a song from a playlist"<<endl;
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
            cout<<"which playlist are you look for?"<<endl;
            getline(cin,auxString1);
            playlists.findItem(auxString1)->data.removeSongFromPlaylist();
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
            getline(cin,auxString3);
            auxString1= musicList.findItem(auxString3)->data.getKey();
            auxString2 =musicList.findItem(auxString3)->data.getAuthor();
            Node <Music>* musicAux =  new Node<Music>({auxString1,auxString2});
            cout<<"what playlist are you adding "<<musicAux->data.getAuthor()<<" to?"<<endl;
            getline(cin,auxString3);
            playlists.findItem(auxString3)->data.addSong(musicAux);
            menu=0;
        }
        
        if(menu==6) {
            system("clear");
            musicList.~List();
            cout<<"all songs deleted"<<endl;
            cout << "Press any key to continue...";
            cin.ignore();

          
            menu=0;
        }
        
        if(menu ==7) {
            system("clear");
            cout<<"set playlist name: "<<endl;
            getline(cin,auxString1);
            Node<Playlist>* newPlaylist = new Node<Playlist>(auxString1);
            playlists.add(newPlaylist);
            cout << "Press any key to continue...";
            cin.ignore();
            
            system("clear");
            menu = 0;
        };
        
        if(menu ==8) {
            system("clear");
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