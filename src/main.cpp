#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Music.h"
#include "Node.h"
#include "List.h"
#include "Playlist.h"
 
using namespace std;



int main () {
    system("clear");
    int menu =0;
    

    /*
    listaencadeada <musica*>

    musica *musica1 = new musica();
    musica1->setTitulo("MUSICA1");
    
    musica.adicionar();
    */

    //tem que ser array de musica, mas como n tem como fazer array de musica infinita vai ter que fazer alocação dinamica
    // Fazer Destrutor de musica

    string auxString;
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
            getline(cin,auxString);
            music.setTitle(auxString);
            cout<<"set "<<music.getKey()<<" author name "<<endl;
            getline(cin,auxString);
            music.setAuthor(auxString);
            
            cout<<"\n"<<"\033[1m\033[34m" <<music.getKey()<< "\033[0m"<< " was added successfuly"<<endl;
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
            cout<<"set music title"<<endl;
            getline(cin,auxString);
            music.setTitle(auxString);
            cout<<"set "<<music.getKey()<<" author name "<<endl;
            getline(cin,auxString);
            music.setAuthor(auxString);
            musicList.add(music);
            // playlists.findItem().addSong();
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
            cout<<"Name a playlist"<<endl;
            getline(cin,auxString);
            p1.setName(auxString);
            playlists.add(p1);
            
           
            cout << "Press any key to continue...";
            cin.ignore();
            
            system("clear");
            menu = 0;
        };
        if(menu ==8) {
            system("clear");
            //TOO: Achar musica ou playlist
            music.setTitle("So far Away");
            cout<<playlists.printItem()<<endl;
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