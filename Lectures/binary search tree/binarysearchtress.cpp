/*
binary treee adt 
    can use different data structures
    eg
        binary search trees (references)
        avl trees (references)
        heaps (arrays)
        B trees (arrays again)

    sorting
        eg an ordered map
        possible solutions
            sorted array 
                o(log n)
                insertion and deletion is linear time
            ordered linked list
                access insertion and deletion is linear time

        dictionary operations
            key-value pairs
                insert
                delete
                constains
                size
                empty
    
    property
        doesn't have to be complete
        left subtree < parent
        right subtree >= parent

        traversel
            in order traversel (is in the sorted order)
                inorder(left)
                visit
                inorder(right)

        implementation
            Node 
                *leftchild;
                data;
                *rightchild;
            searching: height + 1
                O(h)
            
        Removal, 
            if the node to remove has two children, 
            find the predecessor
                a predecessor is the right most node in the leftsubtree
                the predecessor will not have a right child, 
                it will be the largest value that is still smaller than the node
            or find the successor
                left most node in the right subtree
                will not have a left child
                smallest value that is still larger than the node

*/

class NODE{
    public:
        NODE *left{nullptr};
        int data{};
        NODE *right{nullptr};
};
bool contains(NODE *nd, int x){
    if (nd == nullptr){
        return false;
    } 
    else if (x == nd-> data){
        return true;
    }
    else if (x < nd-> data){
        return contains(nd-> left, x); 
    } else {
        return contains(nd -> right, x);
    }
}
void insert(NODE *nd, int val){        // O(h)
    if (nd == nullptr){
        nd = new NODE;
        nd-> data = val;
        return;
    } else if ( nd-> data < val) {
        insert(nd-> left, val);
    } else {
        insert(nd -> right, val);
    }
}
//wrong remove code
void remove(NODE *nd, int val){
    if (nd != nullptr){
        if (nd-> data == val){
            if ((nd-> left == nullptr) && (nd->right == nullptr)){
                delete nd;
            } else if ( nd->left == nullptr){
                NODE *temp = nd;
                nd = nd->right;
                delete temp;
            } else if ( nd->right == nullptr){
                NODE *temp = nd;
                nd = nd->left;
                delete temp;
            }
        } else if (nd -> data < val){
            remove (nd -> left, val);
        } else{
            remove (nd-> right, val);
        }
    }
}

void remove_2(NODE *nd, int val){   //CODE INCOMPLETE
    NODE *parent{nullptr};
    bool isLeftChild;
    while (nd-> data != val){
        if (nd == nullptr){
            return;
        } else if (val < nd-> data) {
            parent = nd;
            nd = nd-> left;
            isLeftChild = true;

        } else {
            parent = nd;
            nd = nd-> right;
            isLeftChild = false;
        }
    }
    if (isLeftChild){
        parent -> left; 
        // CODE INCOMPLETE
    }
}
