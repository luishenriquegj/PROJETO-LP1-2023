#include <iostream>
#include "List.h"
#include "Node.h"
#include "Music.h"
#include "CompareLists.h"

using namespace std;

bool compareLists(List<Music>& list1, List<Music>& list2){
    Node<Music>* current1 = list1.head;
    Node<Music>* current2 = list2.head;
    if(current1 == nullptr && current2 == nullptr){
        return true;
    }else if(current1 == nullptr &&  current2 != nullptr){
        return false;
    }else if(current1 != nullptr &&  current2 == nullptr){
        return false;
    }
    
    while(current1->next != nullptr){
        if(current1->data.getKey() == current2->data.getKey()){
            cout<<current1->data.getKey()<<current2->data.getKey()<<endl;
            return true;
        }
         current2 = current2->next;
         if(current2->next == nullptr){
            current1 = current1->next;
            current2 = list2.head;
         }
    }

    return false;

}