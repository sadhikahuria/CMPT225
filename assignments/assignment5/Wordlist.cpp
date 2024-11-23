#include "Wordlists.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <fstream>
using std::ifstream;
using std::setprecision;
using namespace std;

// Constructor
Wordlist::Wordlist() : root(nullptr), size(0) {}

// Constructor for reading from a file
Wordlist::Wordlist(const string& filename) : root(nullptr), size(0) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw invalid_argument("Couldn't open file: " + filename);
    }
    string word;
    while (file >> word) {
        insert(word);
    }
    file.close();
}

// Copy Constructor
Wordlist::Wordlist(const Wordlist& other) : root(nullptr), size(0) {
    copyTreeStructure(root, other.root, nullptr);
    this->size = other.size;
}

// Assignment Operator
Wordlist& Wordlist::operator=(const Wordlist& other) {
    if (this == &other) return *this;
    deleteTreeStructure(root);
    copyTreeStructure(root, other.root, nullptr);
    size = other.size;
    return *this;
}

// Destructor
Wordlist::~Wordlist() {
    deleteTreeStructure(root);
}

// Insert a word into the AVL tree
void Wordlist::insert(const string& word) {
    root = addWordNode(root, word);
}

// Remove a word from the AVL tree
bool Wordlist::remove(const string& word) {
    int initialSize = size;
    root = removeWordNode(root, word);
    return size < initialSize;
}

// Get the count of a word
int Wordlist::getCount(const string& word) const {
    AVLTreeNode* current = root;
    while (current) {
        if (word == current->word) {
            return current->count;
        } else if (word < current->word) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return 0;
}

// Check if a word exists in the AVL tree
bool Wordlist::contains(const string& word) const {
    return getCount(word) > 0;
}

// Get the total number of words in the AVL tree
int Wordlist::totalWords() const {
    return calculateTotalWords(root);
}

// Find the most frequent word in the AVL tree
string Wordlist::mostFrequent() const {
    if (!root) throw invalid_argument("Tree is empty");
    AVLTreeNode* mostFrequentNode = nullptr;
    findMostFrequentNode(root, mostFrequentNode);
    return mostFrequentNode->word + " " + to_string(mostFrequentNode->count);
}

// Get the count of singletons (words with frequency 1)
int Wordlist::singletons() const {
    return countSingletonNodes(root);
}

// Print statistics about the AVL tree
void Wordlist::printStatistics() const {
    cout << "Number of different words: " << differentWords() << endl;
    cout << "    Total number of words: " << totalWords() << endl;
    cout << "       Most frequent word: " << mostFrequent() << endl;
    cout << "     Number of singletons: " << singletons()
         << setprecision(0) << fixed
         << " (" << 100.0 * singletons() / differentWords() << "%)"
         << endl;
}

// Print all words in the AVL tree
void Wordlist::printWords() const {
    displayWordsHelper(root);
}

// Helper Functions (Private)

// Calculate the height of a node
unsigned int Wordlist::calculateHeight(AVLTreeNode* node) const {
    return node ? node->height : 0;
}

// Calculate the balance factor of a node
int Wordlist::calculateBalance(AVLTreeNode* node) const {
    return node ? static_cast<int>(calculateHeight(node->left)) - static_cast<int>(calculateHeight(node->right)) : 0;
}

// Perform a left rotation
AVLTreeNode* Wordlist::performLeftRotation(AVLTreeNode* node) {
    AVLTreeNode* newRoot = node->right;
    node->right = newRoot->left;
    if (newRoot->left) newRoot->left->parent = node;
    newRoot->left = node;
    newRoot->parent = node->parent;
    if (node->parent) {
        if (node->parent->left == node)
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
    }
    node->parent = newRoot;
    node->height = 1 + max(calculateHeight(node->left), calculateHeight(node->right));
    newRoot->height = 1 + max(calculateHeight(newRoot->left), calculateHeight(newRoot->right));
    return newRoot;
}

// Perform a right rotation
AVLTreeNode* Wordlist::performRightRotation(AVLTreeNode* node) {
    AVLTreeNode* newRoot = node->left;
    node->left = newRoot->right;
    if (newRoot->right) newRoot->right->parent = node;
    newRoot->right = node;
    newRoot->parent = node->parent;
    if (node->parent) {
        if (node->parent->left == node)
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
    }
    node->parent = newRoot;
    node->height = 1 + max(calculateHeight(node->left), calculateHeight(node->right));
    newRoot->height = 1 + max(calculateHeight(newRoot->left), calculateHeight(newRoot->right));
    return newRoot;
}

// Balance a node in the AVL tree
AVLTreeNode* Wordlist::balanceAVLNode(AVLTreeNode* node) {
    int balance = calculateBalance(node);
    if (balance > 1) {
        if (calculateBalance(node->left) < 0) {
            node->left = performLeftRotation(node->left);
        }
        return performRightRotation(node);
    }
    if (balance < -1) {
        if (calculateBalance(node->right) > 0) {
            node->right = performRightRotation(node->right);
        }
        return performLeftRotation(node);
    }
    return node;
}

// Add a word to the AVL tree (helper)
AVLTreeNode* Wordlist::addWordNode(AVLTreeNode* node, const string& word) {
    if (!node) {
        size++;
        return new AVLTreeNode(word);
    }
    if (word < node->word) {
        node->left = addWordNode(node->left, word);
        node->left->parent = node;
    } else if (word > node->word) {
        node->right = addWordNode(node->right, word);
        node->right->parent = node;
    } else {
        node->count++;
        return node;
    }
    node->height = 1 + max(calculateHeight(node->left), calculateHeight(node->right));
    return balanceAVLNode(node);
}

// Remove a word from the AVL tree (helper)
AVLTreeNode* Wordlist::removeWordNode(AVLTreeNode* node, const string& word) {
    if (!node) return nullptr;
    if (word < node->word) {
        node->left = removeWordNode(node->left, word);
    } else if (word > node->word) {
        node->right = removeWordNode(node->right, word);
    } else {
        if (node->count > 1) {
            node->count--;
            return node;
        }
        if (!node->left && !node->right) {
            delete node;
            size--;
            return nullptr;
        }
        if (!node->left || !node->right) {
            AVLTreeNode* child = node->left ? node->left : node->right;
            child->parent = node->parent;
            delete node;
            size--;
            return child;
        }
        AVLTreeNode* successor = findSmallestNode(node->right);
        node->word = successor->word;
        node->count = successor->count;
        successor->count = 1;
        node->right = removeWordNode(node->right, successor->word);
    }
    node->height = 1 + max(calculateHeight(node->left), calculateHeight(node->right));
    return balanceAVLNode(node);
}

// Find the smallest node (helper)
AVLTreeNode* Wordlist::findSmallestNode(AVLTreeNode* node) const {
    AVLTreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

// Recursively calculate the total number of words
int Wordlist::calculateTotalWords(AVLTreeNode* node) const {
    if (!node) return 0;
    return node->count + calculateTotalWords(node->left) + calculateTotalWords(node->right);
}

// Find the most frequent word node (helper)
AVLTreeNode* Wordlist::findMostFrequentNode(AVLTreeNode* node, AVLTreeNode*& mostFrequent) const {
    if (!node) return mostFrequent;
    if (!mostFrequent || node->count > mostFrequent->count) {
        mostFrequent = node;
    }
    findMostFrequentNode(node->left, mostFrequent);
    findMostFrequentNode(node->right, mostFrequent);
    return mostFrequent;
}

// Count the number of singletons
int Wordlist::countSingletonNodes(AVLTreeNode* node) const {
    if (!node) return 0;
    int left = countSingletonNodes(node->left);
    int right = countSingletonNodes(node->right);
    return (node->count == 1 ? 1 : 0) + left + right;
}

// Copy the AVL tree
void Wordlist::copyTreeStructure(AVLTreeNode*& newRoot, AVLTreeNode* oldRoot, AVLTreeNode* parent) {
    if (!oldRoot) {
        newRoot = nullptr;
        return;
    }
    newRoot = new AVLTreeNode(oldRoot->word);
    newRoot->count = oldRoot->count;
    newRoot->height = oldRoot->height;
    newRoot->parent = parent;
    copyTreeStructure(newRoot->left, oldRoot->left, newRoot);
    copyTreeStructure(newRoot->right, oldRoot->right, newRoot);
}

// Delete the AVL tree
void Wordlist::deleteTreeStructure(AVLTreeNode* node) {
    if (!node) return;
    deleteTreeStructure(node->left);
    deleteTreeStructure(node->right);
    delete node;
}

// Helper to print words in order
void Wordlist::displayWordsHelper(AVLTreeNode* node) const {
    if (!node) return;
    displayWordsHelper(node->left);
    cout << node->word << " " << node->count << endl;
    displayWordsHelper(node->right);
}
