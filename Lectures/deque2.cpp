// deque
// double ended queue
// insert front and back
// remove insert and back

class NODE{
    public:
        int data{};
        NODE *next{nullptr};
        NODE *previous{nullptr};
        NODE(){};
        NODE(int newval): data {newval}{};
};

class LIST{
    public:
        NODE *head{nullptr};
        NODE *tail{nullptr};
        unsigned int count{};

        LIST(){};
        LIST(int val): head {new NODE(val)}{
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

};

int main(){
    return 0;
}
