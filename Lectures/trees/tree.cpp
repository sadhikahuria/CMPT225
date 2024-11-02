#include <iostream>

// David chou


/*

Tree termonoglogy
    nodes = vertices
    root = first node
    edge - line between the nodes

    a tree is connected, means every node is connected

    ALWAYS
    edge + 1 = nodes
    one less edge than nodes
        no cycles. cannot go back to the starting node

    Formal definition
        A tree T is a set of notes that store elements in a 
        parent-child relationship with these properties
            if T is non-empty, it has a node, called the root 
            of T, that has no parent
            Each node v of T different from the root has a unique
            parent node w, every node with parent w is a child of w

        A tree can be defined recursively
            A tree T is either empty or 
            consists of a node r, the root of T, and a set of trees 
            whose roots are the children of r. d


    terms
        parent
        child
        descendants
        ancestors
        siblings
        leaf = last children, doesn't have childs
        path = the sequence of nodes to traverse
        subtree. one node and all its descendants


Tree ADT functions
    Node:
        p.parent(), returns the parent of p 
        p.children()
        p.isRoot()
        p.isLeaf() or p.isExternal
    Tree:
        T.root()
        T.empty()
        T.size()
        

Depth
    the depf of a node p is the length of the path from p to the root
    the number of ancestors, excludoing p

    a recursive defintion of depth i s
        if p is the root, th ethe depth of p is 0
        otherwise, the epth of p is one plus the depth of p's parent

        its running time is O(dp) dp is depth of p


height 
    height of a node p can also be defined recursively
        if p is external, the the height of p is 0
        otherwise the height of p is one plus the max height of a child of p 
        its running time is o(n)


binary tree
    A tree where every nodes can max have 2 children
    A proper tree has 2 and 0 children.

    p.right()
    p.left()

    levels contain at most 2^d nodes
    height count downwards. 
    depth count upwards. 

    h+1  <=  n  <=  2^(h+1)-1
    1  <=  n  <=  2^h -1

    h is 2^(h+1) - 1

    perfect trees and complete tree

    level i has 2^i nodes

    h levels have 2^(h+1) -1


Complete binary trees

    the leaves at most 2 different levels
    the last(bottom) second level is filled
    leaves are to the far left as possible


Balanced 
    leaves are same distance from the root
    if the leaves are at max have a differenre of 1 (AVL tree)


Tree traversal
    pre order
    post order
    in order

*/

// H D I B E A F C J G
// A B D H I E C F G J
// H I D E B F J G C A 

#include <iostream>
class NODE{
    public:
        int data{};
        NODE *right{nullptr};
        NODE *left{nullptr};
};

void visit(NODE *nd){
    std::cout << nd-> data << std::endl;
};

void inOrder(NODE * nd){
    if (nd != nullptr){
        inOrder ( nd -> left);
        visit(nd);
        inOrder( nd -> right );
    }
}

void postOrder(NODE *nd){
    if (nd != nullptr){
        postOrder(nd -> left);
        postOrder(nd -> right);
        visit(nd);
    }
};

void preOrder(NODE *nd){
    if ( nd != nullptr){
        visit (nd);
        preOrder(nd->left);
        preOrder(nd->right);
    }
};
