#include <iostream>
//john edgar


/*

Trees
    root
    node
    edge
    connected graph 
    ONE LESS EDGE THAN NODES

    parent child relation. 
    root doesn't have a parent
    descendant, ancestors, siblings

    leaf doesnt have any children

abstract data type
    only talks about the operations, not the implementation
    eg  describe stack or queue without saying if 
        its a circular array or linkedlist

eg trees functions 
    p.parent()
    p.children()
    p.isRoot()
    p.isLeaf()
    p.root()
    p.empty()
    p.size()

    p.left()
    p.right()


binary tress
    is an ordered tree in which 
    every node has at most two children
    each child node is either a left or right child node
    left node come first in ordering

    a tree is full if each node has 2 or 0 children (cant be 1)

    height of tree
        longest path from root to leaf
    facts abt tree
        h+1 <= n <= 2^(h+1) -1
        1 <= nE <= 2*h
        h <= nI <=  2^h -1
        log(n+1) -1 <= h <= n-1

    perfect binary tree
        no node has only 1 child
        h has
            2^(h+1) -1 
        each level doubles the number of nodes
    
    COMPLETE BINARY TREE
        leaves on at most 2 levels
        second to bottom level is filled
        leaves are to the left as possible

    balanced binary tree
        we will look at AVL trees
        O(log(n)) for height

    tree traversals
        visit each node 
        traversel algorithms are ususally recursives

        preorder
        postorder
    

*/

class NODE{
    public:                 //only a template
        NODE *leftchild;
        NODE *rightchild;
};

void visit(NODE* nd){};     //template


void inOrder(NODE* nd){     //only a template for traversing
    
    if (nd != nullptr){     

        inOrder( nd -> leftchild);
        visit(nd);
        inOrder(nd-> rightchild);
    }
}
