#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

// AVL Tree Node class
class AVLTreeNode {
public:
    string word;                     // The word stored in the node
    unsigned int count;              // Count of occurrences of the word
    unsigned int height;             // Height of the node in the AVL tree
    AVLTreeNode* parent;             // Pointer to the parent node
    AVLTreeNode* left;               // Pointer to the left child node
    AVLTreeNode* right;              // Pointer to the right child node

    // Constructor to initialize a node with a word
    AVLTreeNode(const string& w) 
        : word(w), count(1), height(0), parent(nullptr), left(nullptr), right(nullptr) {}
};

// Wordlist class
class Wordlist {
private:
    AVLTreeNode* root;               // Root of the AVL tree
    unsigned int size;               // Number of unique words in the tree

    // Helper functions for AVL tree operations and recursion
    unsigned int calculateHeight(AVLTreeNode* node) const;
    int calculateBalance(AVLTreeNode* node) const;
    AVLTreeNode* performLeftRotation(AVLTreeNode* node);
    AVLTreeNode* performRightRotation(AVLTreeNode* node);
    AVLTreeNode* balanceAVLNode(AVLTreeNode* node);
    AVLTreeNode* addWordNode(AVLTreeNode* node, const string& word);
    AVLTreeNode* removeWordNode(AVLTreeNode* node, const string& word);
    AVLTreeNode* findSmallestNode(AVLTreeNode* node) const;
    void displayWordsHelper(AVLTreeNode* node) const;
    void copyTreeStructure(AVLTreeNode*& newRoot, AVLTreeNode* oldRoot, AVLTreeNode* parent);
    void deleteTreeStructure(AVLTreeNode* node);
    int calculateTotalWords(AVLTreeNode* node) const;
    AVLTreeNode* findMostFrequentNode(AVLTreeNode* node, AVLTreeNode*& mostFrequent) const;
    int countSingletonNodes(AVLTreeNode* node) const;

public:
    // Constructors and destructor
    Wordlist();                                      // Default constructor
    Wordlist(const Wordlist& other);                 // Copy constructor
    Wordlist& operator=(const Wordlist& other);      // Assignment operator
    Wordlist(const string& filename);                // Constructor to build from a file
    ~Wordlist();                                     // Destructor

    // Core functionality
    void insert(const string& word);                 // Insert a word into the AVL tree
    bool remove(const string& word);                 // Remove a word from the AVL tree
    int getCount(const string& word) const;          // Get the count of a word
    bool contains(const string& word) const;         // Check if a word exists in the tree
    int differentWords() const { return size; }      // Get the number of unique words
    int totalWords() const;                          // Get the total word count
    string mostFrequent() const;                     // Get the most frequent word
    int singletons() const;                          // Get the count of words with frequency 1
    void printStatistics() const;                    // Print statistics about the word list
    void printWords() const;                         // Print all words in order with their counts
    AVLTreeNode* getRoot() const { return root; };   // DO NOT REMOVE
};
