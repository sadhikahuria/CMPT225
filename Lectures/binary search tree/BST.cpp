/*
worst case for insertion is 
    sorted order
    eg . insert 1, 2, 3, 4, 5 ...

balanced BSTs are the ideal

binary search tree running time = 
    n* (insertion cost) + traversal
    n * O(h) + O(n)
    O(n*h)



Types of balanced BSTs

    Perfect trees
        have your last level filled
        leaves = 2^(h+1) -1
        ideal, but only works for n = 0, 1, 3, 7, 15

    Complete tree
        last second level is filled
        fill the nodes from left to right
        hard to maintain for BST

    Balanced Tree
        AVL trees
            self balancing trees
            create invariants to guarantee a minimum tree density
            invariant is a property that is always true
            density is the ratio from nodes to height
            minimum density results in height of O(log(n))

            height
                for every node, the right and the left subtree's height should only differ by 1

            depth balanced trees (red-black tree)
                depth of two leaves differ by 2 or less
                use rotations

            all leaves at the same level
                b-trees

        AVL trees
            height invariant


ROTATIONS
    BST insert alogirthm
    

    */

class avl_node{
    public:
        int data{};
        avl_node* parent{nullptr};
        avl_node* left{nullptr};
        avl_node* right{nullptr};
        unsigned int height{};
};
