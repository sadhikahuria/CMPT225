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

PlayList::PlayList(){
    head = nullptr;
    num_songs = 0;
}

PlayList::PlayList(const PlayList& pl){

    if (pl.head == nullptr){    // checking if the list is empty
        head = nullptr;
        num_songs = 0;
    } 
    else {                      
        head = new PlayListNode(pl.head -> song);  // allocate memory for head
        PlayListNode *current = head;
        PlayListNode *plcurrent = pl.head;

        while( plcurrent != nullptr ){             // copy the data
            plcurrent = plcurrent -> next;
            current -> next = new PlayListNode(plcurrent -> song);
            current = current -> next;
        }
        num_songs = pl.num_songs;       // intialize size
    }
}


PlayList::~PlayList(){
    if(head != nullptr){
        PlayListNode *current = head;       // anchoring

        while( current != nullptr ){        // traversing
            head = head-> next;
            delete current;                 // deallocating
            current = head;
        }
        head = nullptr;

        num_songs = 0;                      // declaring empty list
    }
}

PlayList& PlayList::operator=(const PlayList &pl){
    if (this != &pl){                       // if not self assignmnent

        while(head != nullptr){             // deleting
            PlayListNode *temp = head;
            head = head -> next;
            delete temp;
        }

        if (pl.head == nullptr){            // if list is empty
        head = nullptr;
        num_songs = 0;
        } 
        else {                              
            head = new PlayListNode(pl.head -> song);
            PlayListNode *current = head;       //anchoring new list
            PlayListNode *plcurrent = pl.head;  //anchoring old list

            while( plcurrent != nullptr ){      //traversing
                plcurrent = plcurrent -> next;
                current -> next = new PlayListNode(plcurrent -> song);
                current = current -> next;
            }
        }
        num_songs = pl.num_songs;               // intializing size


    }

    return *this;
} 



void PlayList::insert(Song sng, unsigned int pos){
    if ( (0 <= pos) && (pos <= num_songs)){             // validing the position

        PlayListNode *newnode = new PlayListNode(sng);  // creating the node for the new song
        
        if( pos == 0){                                  // checking if the new node needs to be head
            newnode -> next = head;
            head = newnode;
            num_songs++;
        } 
        else {

            PlayListNode *track = head;                 // anchoring
            for (unsigned int i = 0; i < pos-1; i++){   // traversing
                track = track -> next;
            }

            newnode -> next = track-> next;             // inserting the node
            track -> next = newnode;
            num_songs++;
        }

        return;
    } else {

        return;                                         // if position not valid
    }
}


Song PlayList::remove(unsigned int pos){
    if ( (0 <= pos) && ( pos < num_songs)){             // checking position parameters

        PlayListNode *temp = head;                      // anchoring

        if (pos == 0){                                  // if removing head
            head = head -> next;                        // reintialzing the head
            Song mainsong = temp -> song;               
            delete temp;                                // deallocating memory for the node
            temp = nullptr;
            num_songs--;                                // updating size
            return mainsong;
        }
        else
        {   
            PlayListNode *previous = temp;              // anchoring
            temp = temp -> next;
            for( unsigned int i = 0; i < pos -1; i++){  //traversing
                temp = temp -> next;
                previous = previous -> next;
            }   
            Song mainsong = temp -> song;
            previous -> next = temp -> next;
            delete temp;                                // deallocating
            num_songs--;
            return mainsong;                            // returning song
        }
    } 
    else {
        cout << "invalid position\n" << endl;
        throw out_of_range("Invalid position");         // if position not valid, throw
    }
}


void PlayList::swap(unsigned int pos1, unsigned int pos2){
    if ( ( pos1 >= 0) && ( pos2 >= 0) && (pos2 < num_songs) && (pos1 < num_songs) ){    // validing the parameters 

        if (pos1 == pos2){                      // if both positions are the same, return
            return;
        }

        if (pos1 > pos2) std::swap(pos1, pos2);         // keeping position 2 greater than position 1 for simplicity

        PlayListNode *node1 = head;                     //anchoring
        PlayListNode *pos1_previous = nullptr;
        PlayListNode *node2 = head;                     //anchoring
        PlayListNode *pos2_previous = nullptr;

        for ( unsigned int i = 0; i < pos1; i++)        // traversing
        {
            pos1_previous = node1;
            node1 = node1 -> next;
        }

        
        for ( unsigned int i = 0; i < pos2; i++)        // traversing
        {
            pos2_previous = node2;
            node2 = node2 -> next;
        }
    
        PlayListNode *temp = node2 -> next;             // storing a node, so it doesn't get lost

        if (node1 == pos2_previous)                     // if the positions are back to back 
        {
            node2 -> next = node1;
        } 
        else {                                          // if positions are not back to back
            node2 -> next = node1 -> next;
            pos2_previous -> next = node1;
        }
        node1 -> next = temp;

        if (pos1_previous != nullptr){                  // if position 1 is not head
            pos1_previous -> next = node2;
        } else {
            head = node2;
        }


        return;
        
    }
    else {
        cout << "invalid positions" << endl;            // if entered invalid positions
        return;
    }
}


Song PlayList::get(unsigned int pos) const{

    if ( (0 <= pos) && ( pos < num_songs) ) {           // validing position

        PlayListNode *temp = head;                      // anchoring

        for( unsigned int i = 0; i < pos; i++){         //traversing
            temp = temp -> next;
        }   
        Song mainsong = temp -> song;                   // storing and returning song
        return mainsong;
        
    } 
    else {
        cout << "invalid position\n" << endl;           // if position invalid
        throw out_of_range("Invalid position");
    }
}


unsigned int PlayList::size() const{
    return num_songs;                                   // returing private variable 
}

