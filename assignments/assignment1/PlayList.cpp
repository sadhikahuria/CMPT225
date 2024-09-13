// Write your name and date here
#include "PlayList.h"
#include "Song.h"
#include <iostream>

// PlayList method implementations go here

// Play List definitions

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

        while( (plcurrent -> next) != nullptr ){
            plcurrent = plcurrent -> next;
            current -> next = new PlayListNode(plcurrent -> song);
            current = current -> next;
        }
    }
}

// POST: dynamic memory associated with object is deallocated
PlayList::~PlayList(){
    if(head != nullptr){
        PlayListNode *current = head;
        PlayListNode *nextnode;

        while( current != nullptr ){
            nextnode = current-> next;
            delete current;
            current = nextnode;
        }
        head = nullptr;
        current = nullptr;
        nextnode = nullptr;
        num_songs = 0;
    }
}

// Mutators
// PRE: 0 <= i <= length of list
// PARAM: pos - 0-based insertion position
//        sng - Song to be inserted pos
void PlayList::insert(Song sng, unsigned int pos){
    if ( (0 <= pos) && (pos < num_songs)){
        
        PlayListNode *newnode = new PlayListNode(sng);
        
        if( pos == 0){
            newnode -> next = head;
            head = newnode;
            num_songs++;
        } 
        else {

            PlayListNode *track = head -> next;
            PlayListNode *previous = head;
            for (unsigned int i = 0; i < pos-1; i++){
                track = track -> next;
                previous = previous->next;
            }

            newnode -> next = track;
            previous -> next = newnode;
            num_songs++;
        }
    }
}

// PRE: 0 <= pos <= length of list-1
// PARAM: pos - 0-based position of element to be removed and returned
// POST: Song at position pos is removed and returned
Song PlayList::remove(unsigned int pos){
    if ( (0 <= pos) && ( pos > num_songs)){
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
    } 
    else {
        cout << "invalid position\n" << endl;
    }
}

// PRE: 0 <= pos1, pos2 <= length of list-1
// PARAM: pos1, pos2 - 0-based positions of elements to be swapped
// POST: Songs at positions pos1 and pos2 are swapped
void PlayList::swap(unsigned int pos1, unsigned int pos2){
    if ( ( pos1 >= 0) && ( pos2 >= 0) && (pos2 < num_songs) && (pos1 < num_songs) ){
        if (pos1 == pos2){
            return;
        }
        PlayListNode *nodepos1 = head;
        PlayListNode *pos1_previous;
        PlayListNode *nodepos2 = head;
        PlayListNode *pos2_previous;

        if ( pos1 != 0){
            pos1_previous = nodepos1;
            nodepos1 = nodepos1 -> next;
            for ( int i = 0; i < pos1 -1; i++)
            {
                pos1_previous = pos1_previous -> next;
                nodepos1 = nodepos1 -> next;
            }
        }

        
        if ( pos2 != 0){
            pos2_previous = nodepos2;
            nodepos2 = nodepos2 -> next;
            for ( int i = 0; i < pos2 -1; i++)
            {
                pos2_previous = pos2_previous -> next;
                nodepos2 = nodepos2 -> next;
            }
        }

        if (pos1 == 0){
            PlayListNode *temp = nodepos2;
            nodepos1 -> next = nodepos2 -> next;
            temp -> next = nodepos1 -> next;
            pos2_previous -> next = nodepos1;
            head = nodepos2;

            return;

        }

        
        if (pos2 == 0){
            PlayListNode *temp = nodepos1;
            nodepos2 -> next = nodepos1 -> next;
            temp -> next = nodepos2 -> next;
            pos1_previous -> next = nodepos2;
            head = nodepos1;

            return;

        }

        PlayListNode *temp = nodepos2;
        nodepos1 -> next = nodepos2 -> next;
        temp -> next = nodepos1 -> next;

        pos1_previous-> next = nodepos2;
        pos2_previous -> next = nodepos1;

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
    if ( (0 <= pos) && ( pos > num_songs)){
        PlayListNode *temp = head;
        if (pos == 0){
            Song mainsong = temp -> song;
            return mainsong;
        }
        else
        {   
            for( int i = 0; i < pos; i++){
                temp = temp -> next;
            }   
            Song mainsong = temp -> song;
            return mainsong;
        }
    } 
    else {
        cout << "invalid position\n" << endl;
    }
}

// POST: returns the number of songs in the PlayList
unsigned int PlayList::size() const{
    return num_songs;
}


