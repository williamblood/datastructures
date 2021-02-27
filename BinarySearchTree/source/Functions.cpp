/*
	Blood, William

	February 26, 2021

	CS A200
	Lab 2 - BST
*/

#include "BST.h"

using namespace std;

//Definition function nonRecursiveInsert
void BST::nonRecursiveInsert(int elemToInsert)
{
	if (root == nullptr)
	{
		root = new Node;
		root->data = elemToInsert;
	}
	else
	{
		Node* parent = root;
		Node* ptrToCurrNode = root;
		bool duplicate = false;

		while (ptrToCurrNode != nullptr)
		{
			parent = ptrToCurrNode;
			
			if (ptrToCurrNode->data == elemToInsert)
			{
				cerr << "The item to insert is already in the list."
					<< " Duplicates are not allowed."
					<< endl;
				ptrToCurrNode = nullptr;
				duplicate = true;
			}
			else if (ptrToCurrNode->data > elemToInsert)
				ptrToCurrNode = ptrToCurrNode->llink;
			else if (ptrToCurrNode->data < elemToInsert)
				ptrToCurrNode = ptrToCurrNode->rlink;
		}

		if (!duplicate) 
		{
			Node* newNode = new Node;
			newNode->data = elemToInsert;
			count++;

			if (parent->data > elemToInsert)
				parent->llink = newNode;
			else if (parent->data < elemToInsert)
				parent->rlink = newNode;
		}
	}
}

//Definition function nonRecursiveInorder
void BST::nonRecursiveInorder() const
{
	stack<Node*> vertices;

	Node* ptrToCurrNode = root;

	while (ptrToCurrNode != nullptr || !vertices.empty())
	{
		// Traverses left subtree tracking visited nodes
		while (ptrToCurrNode != nullptr)
		{
			vertices.push(ptrToCurrNode);
			ptrToCurrNode = ptrToCurrNode->llink;
		}

		// Stores and prints Inorder node
		ptrToCurrNode = vertices.top();
		vertices.pop();

		cout << ptrToCurrNode->data << " ";

		// Traverses right subtree
		ptrToCurrNode = ptrToCurrNode->rlink;
	} 
}
