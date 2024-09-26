#include <iostream>
#include <vector>


class Queue{
    private:
        std::vector<int> data;

    private:
        void enqueue(int value) {
            data.push_back(value);
        }

        int dequeue(){
            int first{data[0]};
            data.erase(data.begin());
            return first;

        }

};

int main(){

    std::vector<int> numbers{10,20,30,40,50};

    int second {numbers[1]};
    
    numbers.push_back(60);
    
    numbers.pop_back();

    int last{ numbers[numbers.size() -1] };

    numbers.pop_back();

     




    return 0;

}
