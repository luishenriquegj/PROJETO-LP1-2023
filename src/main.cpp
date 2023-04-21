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


    while(menu !=4){
        cout<<"WELCOME TO C0DEM4N"<<endl;
        cout<<"Main menu:"<<endl;
        cout<<"select an option:"<<endl;
        cout<<"1 - add new song to a playlist"<<endl;
        cout<<"2 - remove a song from a playlist"<<endl;
        cout<<"3 - remove a song from all playlists"<<endl;
        cout<<"4 - show all songs from a playlist"<<endl;
        cout<<"5 - exit program"<<endl;
        
        cin>> menu;
        cin.ignore();

        if(menu ==1) {
            system("clear");
            cout<<"set music title"<<endl;
            getline(cin,auxString);
            music.set_titulo(auxString);
            cout<<"set "<<music.get_titulo()<<" author name"<<endl;
            getline(cin,auxString);
            music.set_autor(auxString);
            cout<<music.get_titulo()<<" was added successfuly"<<endl;
            musicList.add(music);
            
            cout << "Press any key to continue...";
            cin.ignore();
            
            system("clear");
            menu = 0;
            
        }

        if(menu ==2) {
            system("clear");
            //TODO: remover musica na playlsit
            music.set_titulo("So far Away");
            cout<<music.get_titulo()<<endl;
            menu = 0;
            cout << "Press any key to continue...";
            cin.ignore();
            system("clear");
        }

        if(menu ==3) {
            system("clear");
            //TOO: remover musica de todas as playlsit
            music.set_titulo("So far Away");
            cout<<music.get_titulo()<<endl;
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
            cout<<"Exiting C0DEM4N"<<endl;
            system("clear");
            return 0;
        }

    };
}