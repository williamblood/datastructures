/*
	Bearden, Reese
	Brewington, Brent
	Kanoyan, Niko
	Mai, Vy
	Wang Chin, Davey

	September 10, 2020

	CS A200
	Lab 2 - BST
*/


#include "BST.h"

using namespace std;

// Definition function insert (non-recursive) 
void BST::insert(int insertItem)
{
	Node* ptr = root;
	Node* parent = root;

	if (root == nullptr)
	{
		root = new Node;
		root->data = insertItem;
	}
	else
	{
		while (ptr != nullptr)
		{
			parent = ptr;
			if (ptr->data > insertItem)
			{
				ptr = ptr->llink;
			}
			else if (ptr->data < insertItem)
			{
				ptr = ptr->rlink;
			}
		}

		Node* newNode = new Node;
		newNode->data = insertItem;

		if (parent->data > insertItem)
		{
			parent->llink = newNode;
		}
		else if (parent->data < insertItem)
		{
			parent->rlink = newNode;
		}
	}
}

// Definition function totalNodes
int BST::totalNodes() const
{
	return totalNodes(root);
}

// Definition function totalNodes (recursive)
int BST::totalNodes(const Node* p) const
{
	int total = 1;

	if (p == nullptr)
		return 0;
	else
	{
		total += totalNodes(p->llink);
		total += totalNodes(p->rlink);	
	}

	return total;
}

// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		preorderTraversal(root);
	}
}

// Definition overloaded function preorderTraversal (recursive)
void BST::preorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		preorderTraversal(p->llink);
		preorderTraversal(p->rlink);
	}
}

// Definition overloaded function postorderTraversal
void BST::postorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		postorderTraversal(root);
	}
}

// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		postorderTraversal(p->llink);
		postorderTraversal(p->rlink);
		cout << p->data << " ";
	}
}