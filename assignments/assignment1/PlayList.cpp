/*
    Author: Sadhika Huria
    CMPT 225 D200 Fall 2024
    Date: Sep 14, 2024
*/


#include "PlayList.h"
#include "Song.h"
#include <iostream>
#include <utility>

using namespace std;

// Constructors and destructor
// POST: head of list is set to nullptr
PlayList::PlayList(){
    head = nullptr;
    num_songs = 0;
}

// PARAM: pl - PlayList to be copied
// POST: new PlayList is created that is a deep copy of pl
PlayList::PlayList(const PlayList& pl){

    if (pl.head == nullptr){
        head = nullptr;
        num_songs = 0;
    } 
    else {
        head = new PlayListNode(pl.head -> song);
        PlayListNode *current = head;
        PlayListNode *plcurrent = pl.head;

        while( plcurrent != nullptr ){
            plcurrent = plcurrent -> next;
            current -> next = new PlayListNode(plcurrent -> song);
            current = current -> next;
        }
        num_songs = pl.num_songs;
    }
}

// POST: dynamic memory associated with object is deallocated
PlayList::~PlayList(){
    if(head != nullptr){
        PlayListNode *current = head;

        while( current != nullptr ){
            head = head-> next;
            delete current;
            current = head;
        }
        head = nullptr;

        num_songs = 0;
    }
}

PlayList& PlayList::operator=(const PlayList &pl){
    if (this != &pl){

        while(head != nullptr){
            PlayListNode *temp = head;
            head = head -> next;
            delete temp;
        }
        if (pl.head == nullptr){
        head = nullptr;
        num_songs = 0;
        } 
        else {
            head = new PlayListNode(pl.head -> song);
            PlayListNode *current = head;
            PlayListNode *plcurrent = pl.head;

            while( plcurrent != nullptr ){
                plcurrent = plcurrent -> next;
                current -> next = new PlayListNode(plcurrent -> song);
                current = current -> next;
            }
        }
        num_songs = pl.num_songs;


    }

    return *this;
} 


// Mutators
// PRE: 0 <= i <= length of list
// PARAM: pos - 0-based insertion position
//        sng - Song to be inserted pos
void PlayList::insert(Song sng, unsigned int pos){
    if ( (0 <= pos) && (pos <= num_songs)){
        
        PlayListNode *newnode = new PlayListNode(sng);
        
        if( pos == 0){
            newnode -> next = head;
            head = newnode;
            num_songs++;
        } 
        else {

            PlayListNode *track = head;
            for (unsigned int i = 0; i < pos-1; i++){
                track = track -> next;
            }

            newnode -> next = track-> next;
            track -> next = newnode;
            num_songs++;
        }
    } else {
        cout << "invalid position" << endl;
    }
}

// PRE: 0 <= pos <= length of list-1
// PARAM: pos - 0-based position of element to be removed and returned
// POST: Song at position pos is removed and returned
Song PlayList::remove(unsigned int pos){
    //if ( (0 <= pos) && ( pos < num_songs)){
        PlayListNode *temp = head;
        if (pos == 0){
            head = head -> next;
            Song mainsong = temp -> song;
            delete temp;
            temp = nullptr;
            num_songs--;
            return mainsong;
        }
        else
        {   
            PlayListNode *previous = temp;
            temp = temp -> next;
            for( int i = 0; i < pos -1; i++){
                temp = temp -> next;
                previous = previous -> next;
            }   
            Song mainsong = temp -> song;
            previous -> next = temp -> next;
            delete temp;
            num_songs--;
            return mainsong;
        }
    //} 
    //else {
      //  cout << "invalid position\n" << endl;
    //}
}

// PRE: 0 <= pos1, pos2 <= length of list-1
// PARAM: pos1, pos2 - 0-based positions of elements to be swapped
// POST: Songs at positions pos1 and pos2 are swapped
void PlayList::swap(unsigned int pos1, unsigned int pos2){
    if ( ( pos1 >= 0) && ( pos2 >= 0) && (pos2 < num_songs) && (pos1 < num_songs) ){
        if (pos1 == pos2){
            return;
        }

        if (pos1 > pos2) std::swap(pos1, pos2);

        PlayListNode *node1 = head;
        PlayListNode *pos1_previous = nullptr;
        PlayListNode *node2 = head;
        PlayListNode *pos2_previous = nullptr;

        for ( int i = 0; i < pos1; i++)
        {
            pos1_previous = node1;
            node1 = node1 -> next;
        }

        
        for ( int i = 0; i < pos2; i++)
        {
            pos2_previous = node2;
            node2 = node2 -> next;
        }
    
        PlayListNode *temp = node2 -> next;

        if (node1 == pos2_previous)
        {
            node2 -> next = node1;
        } 
        else {
            node2 -> next = node1 -> next;
            pos2_previous -> next = node1;
        }
        node1 -> next = temp;

        if (pos1_previous != nullptr){
            pos1_previous -> next = node2;
        } else {
            head = node2;
        }


        return;
        
    }
    else {
        cout << "invalid positions" << endl;
        return;
    }
}

// Accessor
// PRE: 0 <= pos <= length of list-1
// PARAM: pos - 0-based position of element to be returned
// POST: returns the Song at position pos
Song PlayList::get(unsigned int pos) const{
    //if ( (0 <= pos) && ( pos < num_songs)){
        PlayListNode *temp = head;

        for( int i = 0; i < pos; i++){
            temp = temp -> next;
        }   
        Song mainsong = temp -> song;
        return mainsong;
        
    //} 
   // else {
     //   cout << "invalid position\n" << endl;
    //}
}

// POST: returns the number of songs in the PlayList
unsigned int PlayList::size() const{
    return num_songs;
}

