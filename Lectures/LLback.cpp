//recursive method to print linked list

#include <iostream>

class NODE{
    public:
    int data{};
    NODE *next{};
    NODE(){
        next = nullptr;
    }
    NODE(int newdata){
        data = newdata;
        next = nullptr;
    }

};

class LIST{
    public:
    NODE *head{nullptr};
    unsigned count{};
    
    LIST(){
        NODE *newnode {new NODE()};
        head = newnode;
        count = {1};
    }
    LIST(int somedata){
        NODE *newnode {new NODE(somedata)};
        head = newnode;
        count = {1};
    }
    ~LIST(){
        NODE *current {head};
        for (unsigned int i = 0; i < count; i++){
            current = current -> next;
            delete head;
            head = current;
        }
    }
    void insert(int num){
        NODE* newnode {new NODE(num)};
        NODE* current {head};
        while(current->next != nullptr){
            current = current->next;
        }
        current-> next = newnode;
        count++;

    }
    void printlistbackhelper(NODE *current){
        if (current->next != nullptr){
            NODE *temp {current};
            printlistbackhelper(current->next);
            std::cout << current->data << '\n';
            return;
        }
    }
    void printlistback(){
        printlistbackhelper(head);
    }
    LIST& operator=(const LIST &other){
        if (this != &other){
            NODE *current {head};
            while(current != nullptr){
                current = current -> next;
                delete head;
                head = current;
            }
            count = 1;
            head = new NODE(other.head -> data);
            NODE *othercur = other.head->next;
            current = head;
            while(othercur != nullptr){
                current -> next = new NODE(othercur->data);
                current = current->next;
                othercur = othercur->next;
            }
            count = other.count;
        }
        return *this;
    }

};


int main(){
    LIST list(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.printlistback();
    LIST list2;
    list2 = list;
    list2.printlistback();
    return 0;
}   

