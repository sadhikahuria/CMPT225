// deque
// double ended queue
// insert front and back
// remove insert and back
#include <iostream>

class NODE{
    public:
        int data{};
        NODE *next{nullptr};
        NODE *previous{nullptr};
        NODE(){};
        NODE(int newval): data {newval}{};
};

class DEQUE{
    private:
        NODE *head{nullptr};
        NODE *tail{nullptr};
        unsigned int count{};

    public:
        DEQUE(){};
        DEQUE(int val): head {new NODE(val)}{
            tail = head;
            count++;
        };
        void insertfront(int newval){
            NODE *toinsert {new NODE(newval)};
            toinsert -> next = head;
            head -> previous = toinsert;
            head = toinsert;
            count++;
        }
        void insertback(int newval){
            NODE *toinsert {new NODE(newval)};
            tail -> next = toinsert;
            toinsert -> previous = tail;
            tail = toinsert;
            count++;
        }
        int removeback(){
            if (count != 0){
                NODE *toremove {tail};
                tail = tail -> previous;
                tail -> next = nullptr;
                int returned {toremove -> data};
                delete toremove;
                count--;
                return returned;
            }
        }
        int removefront(){
            if (count != 0){
                NODE *toremove {head};
                head = head-> next;
                head-> previous = nullptr;
                int returned {toremove -> data};
                delete toremove;
                count--;
                return returned;
            }
        }

        int size(){
            return count;
        }

        void print(){
            if (head != nullptr){
                NODE *current = head;
                while (current != nullptr){
                    std::cout << current -> data << std::endl;
                    current = current -> next;
                }
            }
        }

        void reverse(){
            NODE *current = head;
            while (current != nullptr){
                NODE *currentnext = current -> next;
                current -> next = current -> previous;
                current -> previous = currentnext;
                current = currentnext;
            }
            NODE *newhead = tail;
            tail = head;
            head = newhead;
        }
};

int main(){
    DEQUE list(1);
    list.insertback(2);
    list.insertback(3);
    list.insertback(4);
    list.insertback(5);
    list.insertback(6);
    list.print();
    list.reverse();
    list.print();
    return 0;
}
