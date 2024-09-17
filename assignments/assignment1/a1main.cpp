/*

Author: Sadhika Huria
CMPT 225 D200 Fall 2024
Date: Sep 14, 2024

    Write O(n) worst case 
    
    PlayList:

        default constructor             O(1)
            intializing head and
            count, constant time

        destructor                      O(n)
            deleting all the nodes, 
            traversing, O(n) time

        copy constructor                O(n)
            coping all the nodes, 
            traversing, O(n) time

        overloaded operator             O(n)
            combination of destuctor 
            and copy constructor 
            adding the two, o(n) time

        insert                          O(n)
            traversing through the 
            worst position, n, 
            O(n) time

        remove                          O(n)
            removing the worst position, 
            n, O(n) time 

        get                             O(n)
            similar to remove, 
            traversing through the list
            O(n) time

        swap                            O(n)
            traversing through the list
            twice, O(n) time

        size                            O(1)
            returning an unsigned 
            int variable, constant time


    Main function commands:

        enter a song                    O(n)
            using the insert funciton
            O(n) time

        remove a song                   O(n)
            using the remove function
            O(n) time

        swap two songs                  O(n)
            using the swap function
            O(n) time

        print all the songs             O(n)
            traversing through the
            list to print each song
            O(n) time
*/


#include "Song.h"
#include "PlayList.h"
#include <iostream>
#include <sstream>

using namespace std;


// function to valididate position
int if_valid(const PlayList& pl, unsigned int pos){
    if ( ( pos >= 0) && (pos <= pl.size() +1 )) {
        return 1;
    }
    else {
        cout << "Invalid Position.\n"<< endl;
        return 0;
    }
}


int main(){

    int input;
    PlayList myplaylist;

    cout << "Menu:\n"
        << "\t1 - Enter the song in the play list at a given position\n"
        << "\t2 - Remove a song from the play list at a given position\n"
        << "\t3 - Swap two songs in the play list\n"
        << "\t4 - Print all the songs in the play list\n"
        << "\t5 - Quit" << endl;

    while (true){

        cout << "\nEnter 1 (insert), 2 (remove), 3 (swap), 4 (print), 5 (quit): ";
        cin >> input;
        string name;
	    string artist;
	    int length;
        int pos;

        if (input == 1)                 // inserting
        {
            cout << "Song name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Artist: ";
            getline(cin, artist);

            cout << "Length: ";
            cin >> length;

            do{
                cout << "Position (1";
                if (myplaylist.size() == 0 ){
                    cout << "): ";
                }
                else 
                {
                    cout << " to " << myplaylist.size()+1 << "): ";
                }
                cin >> pos;
            } while (!if_valid(myplaylist, pos));

            Song newsong(name, artist, length);
            myplaylist.insert(newsong, pos-1);

            cout << "You entered " << name << " at position " << pos << " in the play list" << endl;
        } 


        else if (input == 2)        // removing
        {
            do{
                cout << "Position (1";
                if (myplaylist.size() == 0 ){
                    cout << "):";
                }
                else 
                {
                    cout << " to " << myplaylist.size() << "):";
                }
                cin >> pos;
            } while (!if_valid(myplaylist, pos));

            Song remove = myplaylist.remove(pos-1);
            cout << "You removed " << remove.getName() << " from the play list." << endl;

        }


        else if ( input == 3)       // swaping
        {
            int pos2;

            do{
                cout << "Swap song at position (1";
                if (myplaylist.size() == 0 ){
                    cout << "):";
                }
                else 
                {
                    cout << " to " << myplaylist.size() << "):";
                }
                cin >> pos;
            } while (!if_valid(myplaylist, pos));

            do{
                cout << "with the song at position (1";
                if (myplaylist.size() == 0 ){
                    cout << "): ";
                }
                else 
                {
                    cout << " to " << myplaylist.size() << "): ";
                }
                cin >> pos2;
            } while (!if_valid(myplaylist, pos));

            myplaylist.swap(pos-1, pos2-1);
            cout << "You swapped the songs at positions " << pos << " and " << pos2 << endl;
            
        } 


        else if (input == 4)        // printing
        {
            for (int i = 1; i <= myplaylist.size(); i++){
                Song newsong = myplaylist.get(i-1);
                cout << "\t" << i << " " << newsong.getName() << " (" << newsong.getArtist() << ") " << newsong.getLength() << "s" << endl;
            }
            
            cout << "There are "<< myplaylist.size() << " songs in the play list." << endl;
        }


        else if (input == 5) {      // to quit
            cout << "You have chosen to quit the program.\n" << endl;
            break;
        }
        
    }

    return 0;
}

