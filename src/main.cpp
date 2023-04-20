#include <iostream>
#include "Music.h"

using namespace std;



int main () {

    int menu =0;

    while(menu !=3){

        Music musica1;

        musica1.set_autor("Avenged");
        musica1.set_titulo("So far Away");
        cout<<musica1.get_titulo()<<endl;
        menu++;
        return 0;
    };
}