#include "Song.h"
#include "PlayList.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    PlayList myplaylist;
    Song song1("hello", "whtever", 234);
    Song song2("ok", "idc", 234);
    myplaylist.insert(song1, 0);
    myplaylist.insert(song2, 1);
    Song get1 = myplaylist.get(0);
    Song get2 = myplaylist.get(1);

    cout << myplaylist.size() << endl;

    return 0;
}
