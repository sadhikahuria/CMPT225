#include <iostream>
#include <vector>


class list{
    private:
        std::vector<int> arr{};
    
    public:
        int find(int val){
            for(int i{}; i < arr.size(); i++){
                if ( arr[i] == val){
                    return i;
                }
            }
            return -1;
        }

        
};

int main(){
    std::vector<double> arr{};
    std::vector<int> arr1(10,2); //10 size, all elements 2
    std::vector<int> arr2({1,2,3,4}); //giving a list
    arr.begin();    //returns pointer to 1 element
    arr.end();      // returns pointer to last element
    arr.front();    //returns first element
    arr.back();     //returns last element

    arr.size();     // returns size
    arr.max_size(); //returns how many elements can fit
    arr.empty();    //checks if its empty

    arr.assign({10});   //assigns new list
    arr.push_back(2);   //inserts back
    arr.pop_back();     //removes back
    arr.insert(arr.begin()+2, 3); //inserts at pos 2
    arr.erase(arr.begin()+5); //removes pos 5
    arr.clear();        //removes everything

    arr.~vector(); //properly destroying it




}

