//vectors and dynamic array

#include <iostream>
#include <string>
#include <vector>

class dymaniclist{
    public:
        int capacity{};
        std::string *arr {new std::string[4]};
        unsigned int count{};

        void resize(){
            if (count == capacity){
                capacity = capacity *2;
                std::string *temp { new std::string[capacity] };
                for (unsigned int i = 0; i < count; i++){
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
            }
        }

};

class vectorlist{
    public:
        std::vector<std::string> arr{};
        //already resizing
        //already deallacting
        //no capacity
        //no size
        int find(std::string str){
            int i{};
            while (i < arr.size() && str != arr[i] ){
                i++;
            }
            if (i == arr.size()){
                return -1;
            }
            else return i;
        }
        //built in assignment operator
}; 

//find functions in documentation for vector
