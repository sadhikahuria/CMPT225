#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class AVLTreeNode {
public:
	// Should have attributes named:
	// parent - pointer to parent
	// left - pointer to left child
	// right - pointer to right child
    AVLTreeNode *parent{nullptr};
    AVLTreeNode *left{nullptr};
    AVLTreeNode *right{nullptr};
	// word - node's string data
	// count - number of times the word appears
	// height - node's height
    unsigned int word{};
    unsigned int count{};
    unsigned int height{};

	// Constructors ...
    AVLTreeNode(){};

};

// Wordlist class
class Wordlist
{
private:
	// Class attributes go here

	// Your class MUST have a root node named root (below)
	AVLTreeNode* root; // DO NOT REMOVE

public:
	// public methods go here
    Wordlist();
    Wordlist(string file1);
    Wordlist(Wordlist &list);
    Wordlist& operator=(const Wordlist &other);
    ~Wordlist();
    unsigned getCount();
    bool contains(string word);
    void insert();
    bool remove(string word);
    unsigned int differentWords();
    unsigned int totalwords();
    string mostFrequent();
    unsigned int singletons();
    void printWords();
    
	// Prints useful statistics about the word list
	void printStatistics() const;

	// Returns the root of the AVL tree
	AVLTreeNode* getRoot() const { return root; }; // DO NOT REMOVE
};