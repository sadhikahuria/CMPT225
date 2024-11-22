#include "Wordlist.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <fstream>
using std::ifstream;
using std::setprecision;
using namespace std;

// Constructor
Wordlist::Wordlist():root(nullptr), size(0){}

// Constructor for the file to read and edit 
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
Wordlist:: Wordlist(const Wordlist& other): root(nullptr), size(0){
	copytree(root, other.root, nullptr);
	this -> size = other.size;
}

// Assignment Operator
Wordlist& Wordlist:: operator=(const Wordlist& other){
	if(this == &other) return*this;
	deletetree(root);
	copytree(root, other.root, nullptr);
	size = other.size;
	return*this;
}

//copytree
void Wordlist::copytree(AVLTreeNode*& newRoot, AVLTreeNode* oldRoot, AVLTreeNode* parent) {
    if (!oldRoot) {
        newRoot = nullptr;
        return;
    }
    newRoot = new AVLTreeNode(oldRoot->word);
    newRoot->count = oldRoot->count;
    newRoot->height = oldRoot->height;
    newRoot->parent = parent;
    copytree(newRoot->left, oldRoot->left, newRoot);
    copytree(newRoot->right, oldRoot->right, newRoot);
}


// Destructor
Wordlist::~Wordlist(){
	deletetree(root);
}

// insertion for AVL tree
void Wordlist:: insert(const string& word){
	root = insertnode(root, word);
}

// removal for AVL tree
bool Wordlist::remove(const string& word){
	int initialsize= size;
	root = removenode(root, word);
	return size < initialsize;
}

//getcount function
int Wordlist::getCount(const string& word) const {
    AVLTreeNode* current = root;
    while (current) {
        if (word == current->word) {
            return current->count; // Return the count if the word is found
        } else if (word < current->word) {
            current = current->left; // Traverse left subtree
        } else {
            current = current->right; // Traverse right subtree
        }
    }
    return 0; // Word not found
}
//contains used with getCount
bool Wordlist::contains(const string& word) const {
    return getCount(word) > 0; // If the count is greater than 0, the word exists
}

// differentWords, already implemented in header file.

// to get the total word count
int Wordlist:: totalWords() const{
	return countotalwords(root);
}

//mostFrequent
string Wordlist::mostFrequent() const {
    if (!root) throw invalid_argument("Tree is empty");
    AVLTreeNode* mostFrequentNode = nullptr;
    findmostfrequent(root, mostFrequentNode);
    return mostFrequentNode->word + " " + std::to_string(mostFrequentNode->count);
}
//used with a helper functionn
AVLTreeNode* Wordlist::findmostfrequent(AVLTreeNode* node, AVLTreeNode*& mostFrequent) const {
    if (!node) return mostFrequent;
    if (!mostFrequent || node->count > mostFrequent->count) {
        mostFrequent = node;
    }
	findmostfrequent(node->left, mostFrequent);
    findmostfrequent(node->right, mostFrequent);
    return mostFrequent;
}

//signletons
int Wordlist::singletons() const {
    return countsingletons(root);
}
//using the helper function countingsingletons
int Wordlist::countsingletons(AVLTreeNode* node) const {
    if (!node) return 0;
    int left = countsingletons(node->left);
    int right = countsingletons(node->right);
    return (node->count == 1 ? 1 : 0) + left + right;
}

// Prints useful statistics about the word list
void Wordlist::printStatistics() const
{
	cout << "Number of different words: " << differentWords() << endl;
	cout << "    Total number of words: " << totalWords() << endl;
	cout << "       Most frequent word: " << mostFrequent() << endl;
	cout << "     Number of singletons: " << singletons()
		<< setprecision(0) << fixed
		<< " (" << 100.0 * singletons() / differentWords() << "%)"
		<< endl;
}

//printWords
void Wordlist::printWords() const {
    printwordshelper(root);
}
//helper function 
void Wordlist::printwordshelper(AVLTreeNode* node) const {
    if (!node) return;
    printwordshelper(node->left);
    cout << node->word << " " << node->count << endl; // Display word and count
    printwordshelper(node->right);
}

//getRoot, already implemented in header file.

//private
//insertion with recursion helper functions 
AVLTreeNode* Wordlist:: insertnode(AVLTreeNode*node, const string& word){
	if(!node){// when the node is null
		size++;
		return new AVLTreeNode(word);
	}
	//recursively insert in the tree
	if(word < node->word){// when the word is less than the root, it goes to left
		node->left = insertnode(node->left, word);
		node->left->parent = node;
	}
	if (word>node->word){// when the word is greater than root, it goes to right
		node->right = insertnode(node->right, word);
		node->right->parent = node;
	}
	else{// when the word already exists, we just increase the count
		node->count++;
		return node;
	}
	node -> height = 1 + max(getheight(node->left), getheight(node->right));
	return balancenode(node);
}

//deletion with recursion helper functions
AVLTreeNode* Wordlist:: removenode(AVLTreeNode* node, const string& word){
	if(!node){
		return nullptr;
	}
	if (word< node-> word){
		node->left = removenode(node->left, word);
	}
	else if(word>node->word){
		node->right = removenode(node->right, word);
	}
	else{
		if(node-> count>1){
			node->count--;
			return node;
		}
		//when the node has no child or is only a leaf
		if(!node->left && !node->right){
			delete node;
			size--;
			return nullptr;
		}
		//this is for when there is only one child
		if(!node->left || !node->right){
			AVLTreeNode* child = node->left ? node->left : node->right;
            child->parent = node->parent;
            delete node;
            size--;
            return child;
		}
		// when the node has 2 children, so we choose the successor here using in order traversal or by choosing the smallest in right subtree
		AVLTreeNode* successor = smallestnode(node->right);
		node->word = successor->word;
		node->count = successor->count;
		successor->count = 1;
		node->right = removenode(node->right, successor->word);
	}
	node->height = 1 + max(getheight(node->left), getheight(node->right));
	return balancenode(node);
}


//balancing helper function 
AVLTreeNode* Wordlist:: balancenode(AVLTreeNode*node){
	int balance= getbalance(node);
	
	//left unbalanced 
	if (balance>1){//LR rotation
		if (getbalance(node->left)<0){
			node->left = leftrotation(node->left);
		}
		return rightrotation(node);//LL rotation 
	}
	//right unbalanced
	if(balance<-1){//RL rotation
		if(getbalance(node->right)>0){
			node->right = rightrotation(node->right);
		}
		return leftrotation(node);//RR rotation
	}
	return node;//when the tree is balanced
}

//left rotation
AVLTreeNode* Wordlist::leftrotation(AVLTreeNode* node) {
    AVLTreeNode* newRoot = node->right;
    node->right = newRoot->left;
    if (newRoot->left) newRoot->left->parent = node;
    newRoot->left = node;
    newRoot->parent = node->parent;
	if (node->parent) {
        if (node->parent->left == node) // Update parent's child pointer
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
    }
	node->parent = newRoot;
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    newRoot->height = 1 + max(getheight(newRoot->left), getheight(newRoot->right));
    return newRoot;

}

//right rotation 
AVLTreeNode* Wordlist::rightrotation(AVLTreeNode* node) {
    AVLTreeNode* newRoot = node->left;
    node->left = newRoot->right;
    if (newRoot->right) newRoot->right->parent = node;
    newRoot->right = node;
    newRoot->parent = node->parent;
	if (node->parent) {
        if (node->parent->left == node) // Update parent's child pointer
            node->parent->left = newRoot;
        else
            node->parent->right = newRoot;
    }
	node->parent = newRoot;
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    newRoot->height = 1 + max(getheight(newRoot->left), getheight(newRoot->right));
    return newRoot;
}

//delete tree recursively
void Wordlist:: deletetree(AVLTreeNode*node){
	if(!node) return;
	deletetree(node->left);
	deletetree(node->right);
	delete node;
	node = nullptr;
}

//height of a node
unsigned int Wordlist :: getheight(AVLTreeNode*node) const{
	if(node){
		return node-> height;
	}
	return 0;
}

//get the balance factor 
int Wordlist::getbalance(AVLTreeNode*node) const{
	if (node){
		return (int)getheight(node->left)-(int)getheight(node->right);
	}
	else{
		return 0;
	}
}

//get the smallest node for in order tranveral
AVLTreeNode*Wordlist:: smallestnode(AVLTreeNode*node) const{
	AVLTreeNode*current = node;
	while(current && current -> left){
		current = current ->left;
	}
	return current;
}

//count total number of words
int Wordlist::countotalwords(AVLTreeNode* node) const {
    if (!node) return 0;
    return node->count + countotalwords(node->left) + countotalwords(node->right);
}

void Wordlist::printTreeStructure(AVLTreeNode* node, int level = 0) const {
    if (node == nullptr) return;

    printTreeStructure(node->right, level + 1);  // Print right subtree
    cout << string(4 * level, ' ') << node->word << " (" << node->count << ")\n";
    printTreeStructure(node->left, level + 1);   // Print left subtree
}
