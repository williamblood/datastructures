#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string> // Need to include for nullptr.			

class Node
{
public:
	Node() : data(0), ptrToNext(nullptr) {}
	Node(int theData, Node *newPtrToNext) 
		: data(theData), ptrToNext(newPtrToNext){}
	Node* getPtrToNext() const { return ptrToNext; }
	int getData( ) const { return data; }
    	void setData(int theData) { data = theData; }
	void setPtrToNext(Node *newPtrToNext) 
		{ ptrToNext = newPtrToNext; }
	~Node(){}
private:
    	int data;		
    	Node *ptrToNext; // Pointer that points to next node.
};


class AnyList
{
public:
	AnyList() : ptrToFirst(nullptr), count(0) {}

	void insertFront(int);	

	void print() const;

	void clearList();
	~AnyList();

private:
	Node *ptrToFirst;
	// Pointer to point to the first node in the list.
	int count;
	// Variable to keep track of number of nodes in the list.
};

#endif