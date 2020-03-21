#include "RedBlackTree.h"

// default constructor
RedBlackTree::RedBlackTree()
: root(nullptr), currentSize(0)
{ }

// copy constructor
RedBlackTree::RedBlackTree(const RedBlackTree & r)
{
	deepCopy(r);
}

RedBlackTree & RedBlackTree::operator=(const RedBlackTree & r)
{
	if (this != &r) { // don't copy self
		deepCopy(r);
	}
	return *this;
}

RedBlackTree::~RedBlackTree()
{
	clearTree(root);
}

int RedBlackTree::size() const { return currentSize; }

// insert data if tree does not contain parameter, no duplicates
bool insert(int num)
{
	
} 