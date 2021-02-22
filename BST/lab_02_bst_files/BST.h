#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

class Node
{
	friend class BST;
public:
	Node(): data(0), rlink(nullptr), llink(nullptr) {}
	~Node(){}
private:
    int data;
    Node *rlink, *llink;
};

class BST
{
public:

	BST() : root(nullptr) {}
	
	void insert(int item); 
	
	void inorderTraversal() const;

	void destroyTree();
	
	~BST();   

	// Declaration function insert (non-recursive) 
	// Inserts element in the BST
	//void insert(int insertItem);

	// Declaration function totalNodes
	// Returns the number of nodes in the BST
	int totalNodes() const;

	// Declaration overloaded function preorderTraversal
	// Prints all nodes in the BST in a preorder sequence
	void preorderTraversal() const;

	// Declaration overloaded function postorderTraversal
	// Prints all nodes in the BST in a postorder sequence
	void postorderTraversal() const;
				
private:	
	Node *root; //Pointer to the root

	void insert(Node* &p, Node *newNode);

	void destroyTree(Node* &p);
	
	void inorderTraversal(const Node* p) const;

	// Declaration overloaded function totalNodes (recursive)
	int totalNodes(const Node *p) const;
	
	// Declaration overloaded function preorderTraversal (recursive)
	void preorderTraversal(const Node *p) const;

	// Declaration overloaded function postorderTraversal (recursive)
	void postorderTraversal(const Node *p) const;

};

#endif