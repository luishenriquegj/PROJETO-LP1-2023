#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Music.h"
#include "Node.h"
#include "Playlist.h"
#include "RemoveSongFromAll.h"
 
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
    while(menu !=10){
        cout<<"Main menu:"<<endl;
        cout<<"select an option:"<<endl;
        cout<<"1 - add new song to system"<<endl;
        cout<<"2 - add new list to a list"<<endl;
        cout<<"3 - remove a song from a playlist"<<endl;
        cout<<"4 - remove a song on system"<<endl;
        cout<<"5 - show all songs on system"<<endl;
        cout<<"6 - add a song to a playlsit"<<endl;
        cout<<"7 - destruct list"<<endl;
        cout<<"8 - create a new playlist"<<endl;
        cout<<"9 - find a playlist"<<endl;
        cout<<"10 - exit program"<<endl;
        cin>> menu;
        cin.ignore();

        if(menu ==1) {
            //adiciona musica ao sistema
            system("clear");
            cout<<"set music title"<<endl;
            getline(cin,auxString1);
            cout<<"set music author"<<endl;
            getline(cin,auxString2);
            Node<Music>* newNode = new Node<Music>({auxString1,auxString2});
            
            cout<<"\n"<<"\033[1m\033[34m" <<newNode->data.getKey()<< "\033[0m"<< " was added successfuly?"<<endl;
            musicList.add(newNode);
            
            
            cout << "Press any key to continue...";
            cin.ignore();
            
            system("clear");
            menu = 0;
            
        }
        if(menu ==2) {
            //adiciona lista a lista
            system("clear");
            cout<<"choose list1 "<<endl;
            List<Music>* newList = new List<Music>();
            int submenu = 1;
            while(submenu ==1){
                system("clear");
                cout<<"set music title"<<endl;
                getline(cin,auxString1);
                cout<<"set music author"<<endl;
                getline(cin,auxString2);
                Node<Music>* auxNode = new Node<Music>({auxString1,auxString2});
                newList->add(auxNode);
                
                cout << "Press 0 to exit or 1 to continue.."<<endl;
                cin>>submenu;
                cin.ignore();
                if(submenu != 0){
                    submenu = 1;
                }
                system("clear");
            }

            musicList.add(newList);
            cout << "Press any key to continue...";
            cin.ignore();
            
            system("clear");
            menu = 0;
            
        }


        if(menu ==3) {
            //remove musica de uma playlist em especifico
            system("clear");
            cout<<"which playlist are you look for?"<<endl;
            getline(cin,auxString1);
            cout<<"wich song you want to remove"<<endl;
            getline(cin,auxString2);
            playlists.findItem(auxString1)->data.removeSongFromPlaylist(auxString2);
            cout << "Press any key to continue...";
            cin.ignore();
            menu = 0;
        }

        if(menu ==4) {
            system("clear");
            //remove musica de todas as playlsit e do sistema
            cout<<"what song do you wish to remove from the database?"<<endl;
            getline(cin,auxString1);
            musicList.removeItem(auxString1);
            removeSongFromAll(playlists,auxString1);
            cout << "Press any key to continue...";
            cin.ignore();
            menu = 0;

        }

        if(menu==5) {
            //mostra todas as musicas do sistema
            system("clear");
            cout << "exibiting all playlist songs..."<<endl;
            musicList.print();
            cout << "Press any key to continue...";
            cin.ignore();
            menu = 0;
        }

        if(menu==6) {
            //escolhe musica do sistema e adiciona a playlist escolhida
            system("clear");
            cout<<"what song are you adding?"<<endl;
            getline(cin,auxString3);
            auxString1 = musicList.findItem(auxString3)->data.getKey();
            auxString2 = musicList.findItem(auxString3)->data.getAuthor();
            Node <Music>* musicAux =  new Node<Music>({auxString1,auxString2});
            cout<<"what playlist are you adding "<<musicAux->data.getAuthor()<<" to?"<<endl;
            getline(cin,auxString3);
            playlists.findItem(auxString3)->data.addSong(musicAux);
            menu=0;
        }
        
        if(menu==7) {
            system("clear");
            musicList.~List();
            playlists.~List();
            cout<<"all deleted"<<endl;
            cout << "Press any key to continue...";
            cin.ignore();
            menu=0;
        }
        
        if(menu ==8) {
            //cria uma nova playlist
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
        
        if(menu ==9) {
            //mostra todas as playlists e seus conteudos
            system("clear");
            playlists.print();
            cout << "Press any key to continue...";
            cin.ignore();
            system("clear");
            menu = 0;
        }
        
        if(menu==10) {
            //fecha o programa
            system("clear");
            cout<< "Exiting C0DEM4N...."<<endl;
            return 0;          
        }
    }

    return 0;
}