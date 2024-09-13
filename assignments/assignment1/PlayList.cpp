// Write your name and date here
#include "PlayList.h"

// PlayList method implementations go here

// Play List definitions

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
//        sng - Song to be insertedpos
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
            for (int i = 0; i < pos-1; i++){
                track = track -> next;
                previous = previous->next;
            }



        }
    }
}
