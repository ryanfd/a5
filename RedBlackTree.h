#pragma once

#include <vector>

using std::vector;

class NodeT {
public:
	int data;
	NodeT* parent;
	NodeT* left;
	NodeT* right;
	bool isBlack;

	NodeT(int x)
	: data(x), parent(nullptr), left(nullptr), right(nullptr), isBlack(false)
	{ }
};

class RedBlackTree {
public:
	// constructors, operators and destructors
	RedBlackTree(); // empty tree, root is null
	RedBlackTree(const RedBlackTree &); // deep copy
	RedBlackTree & operator=(const RedBlackTree &); // deep copy, overloaded assignment operator
	~RedBlackTree(); // deallocate nodes

	// mutators
	bool insert(int); // insert data if tree does not contain parameter, no duplicates
	bool remove(int); // remove parameter and return true, if parameter is not in tree, return false

	// accessors
	bool search(int) const; // return true if parameter is found
	vector<int> search(int, int) const; // return vector containing elements in tree from a to b, ascending order
	vector<int> dump() const; // return vector with all contents of tree
	int size() const; // return number of nodes in tree
	NodeT* getRoot() const; // return pointer to tree's root

private:
	NodeT* root;
	int currentSize;


	// helpers

	// copy data into tree
	void deepCopy(const RedBlackTree & r)
	{
		if (size() > 0) clearTree(root); // empty original tree
		if (r.root != nullptr) root = copyHelper(r.root);
		else root = nullptr;
		currentSize = r.currentSize;
	}

	// pre order traversal and copy nodes
	NodeT* copyHelper(NodeT* node)
	{
		if (node == nullptr) return nullptr;

		NodeT* newNode = new NodeT(node->data);
		newNode->left = copyHelper(node->left);
		if (newNode->left != nullptr) newNode->left->parent = newNode;
		newNode->right = copyHelper(node->right);
		if (newNode->right != nullptr) newNode->right->parent = newNode;

		return newNode;
	}

	// post order traversal and delete nodes
	void clearTree(NodeT* node)
	{
		if (node != nullptr) {
			clearTree(node->left);
			clearTree(node->right);
			delete node;
		} 
	}

	void leftRotate(NodeT* node);
	void rightRotate(NodeT* node);
};