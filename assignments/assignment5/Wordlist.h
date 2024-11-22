#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class AVLTreeNode {
public:
string word;
unsigned int count;
unsigned int height;
AVLTreeNode*parent;
AVLTreeNode*left;
AVLTreeNode*right;

AVLTreeNode(const string &w):
 word(w), count(1), height(0), parent(nullptr), left(nullptr), right(nullptr) {}
};

// Wordlist class
class Wordlist
{
private:
	AVLTreeNode* root; 
	unsigned int size;
	//helper functions to keep the BST properties in check and for recursion 
	unsigned int getheight(AVLTreeNode* node) const;
    int getbalance(AVLTreeNode* node) const;
    AVLTreeNode* leftrotation(AVLTreeNode* node);
    AVLTreeNode* rightrotation(AVLTreeNode* node);
    AVLTreeNode* balancenode(AVLTreeNode* node);
    AVLTreeNode* insertnode(AVLTreeNode* node, const string& word);
    AVLTreeNode* removenode(AVLTreeNode* node, const string& word);
    AVLTreeNode* smallestnode(AVLTreeNode* node) const;
	void printwordshelper(AVLTreeNode* node) const;
    void copytree(AVLTreeNode*& newRoot, AVLTreeNode* oldRoot, AVLTreeNode* parent);
    void deletetree(AVLTreeNode* node);
    int countotalwords(AVLTreeNode* node) const;
    AVLTreeNode* findmostfrequent(AVLTreeNode* node, AVLTreeNode*& mostFrequent) const;
    int countsingletons(AVLTreeNode* node) const;
	
	void mostfrequenthelper(AVLTreeNode* node, int& maxCount, string& frequentWord) const;


public:
	Wordlist();
	Wordlist(const Wordlist& other);
	Wordlist& operator=(const Wordlist& other);
	Wordlist(const string& filename);
	~Wordlist();
	void insert(const string& word);
	bool remove(const string& word);
	int getCount(const string& word) const;
	bool contains(const string& word) const;
	int differentWords() const {return size;}
	int totalWords() const;
	string  mostFrequent() const;
	int singletons() const;
	void printStatistics() const;
	void printWords() const;
	AVLTreeNode* getRoot() const { return root; }; // DO NOT REMOVE
	void printTreeStructure(AVLTreeNode* node, int level) const;
};
