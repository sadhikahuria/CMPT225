/*

Author: Sadhika Huria
CMPT 225 D200 Fall 2024
Date: Sep 14, 2024

    Write O(n) worst case 
    
    PlayList
        default constructor
        destructor
        copy constructor
        overloaded assignement operator
        insert
        remove
        get
        swap
        size

    Main function commands
        enter a song
        remove a song
        swap two songs
        print all the songs
*/


#include "Song.h"
#include "PlayList.h"
#include <iostream>
#include <sstream>

using namespace std;

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

        if (input == 1)
        {
            cout << "Song name: ";
            cin >> name;

            cout << "Artist: ";
            cin >> artist;

            cout << "Length: ";
            cin >> length;

            cout << "Position (1";
            if (myplaylist.size() == 0 ){
                cout << "): ";
            }
            else 
            {
                cout << " to " << myplaylist.size()+1 << "): ";
            }
            cin >> pos;

            Song newsong(name, artist, length);
            myplaylist.insert(newsong, pos-1);

            cout << "You entered " << name << " at position " << pos << " in the play list" << endl;
        } 

        else if (input == 2)
        {
            cout << "Position (1";
            if (myplaylist.size() == 0 ){
                cout << "):";
            }
            else 
            {
                cout << " to " << myplaylist.size() << "):";
            }
            cin >> pos;

            Song remove = myplaylist.remove(pos-1);
            cout << "You removed " << remove.getName() << " from the play list." << endl;

        }

        else if ( input == 3)
        {
            int pos2;

            cout << "Swap song at position (1";
            if (myplaylist.size() == 0 ){
                cout << "):";
            }
            else 
            {
                cout << " to " << myplaylist.size() << "):";
            }
            cin >> pos;

            cout << "with the song at position (1";
            if (myplaylist.size() == 0 ){
                cout << "):";
            }
            else 
            {
                cout << " to " << myplaylist.size() << "):";
            }
            cin >> pos2;

            myplaylist.swap(pos-1, pos2-1);
            cout << "You swapped the songs at positions " << pos << " and " << pos2 << endl;
            
        } 

        else if (input == 4)
        {
            for (int i = 1; i <= myplaylist.size(); i++){
                Song newsong = myplaylist.get(i-1);
                cout << "\t" << i << " " << newsong.getName() << " (" << newsong.getArtist() << ") " << newsong.getLength() << "s" << endl;
            }
            
            cout << "There are "<< myplaylist.size() << " songs in the play list." << endl;
        }

        else if (input == 5) {
            cout << "You have chosen to quit the program.\n" << endl;
            break;
        }

    }

    return 0;
}

