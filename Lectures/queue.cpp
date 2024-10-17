//insert at back
//remove from back

//queue as double-linked list

class NODE{
    public:
        int data{};
        NODE *next{nullptr};
        NODE *previous{nullptr};
        NODE(int newval): data{newval}{};
};

class DEQUE{
    public:
        NODE *head{nullptr};
        NODE *tail{nullptr};
        int count{};
        DEQUE(){};
        DEQUE(int val): head{new NODE(val)} {
            tail = head;
            count++;
        }
        void insert(int newval){
            NODE *toinsert {new NODE(newval)};
            if (tail == nullptr){
                tail = toinsert;
                head = toinsert;
                count++;
                return;
            }
            tail -> next = toinsert;
            toinsert-> previous = tail;
            tail = toinsert;
            count++;
        }
        int remove(){
            if (tail != nullptr && head != nullptr){
                NODE *toremove {head};
                head = head-> next;
                head -> previous = nullptr;
                int removed {toremove -> data};
                delete toremove;
                count--;
                return removed;
            }
        }
};

main(){
    return 0;
}
