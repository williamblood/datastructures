/*
	Blood, William

	September 2, 2020

	CS A200
	Lab 1
*/

#ifndef MIDWESTGRAPH_H
#define MIDWESTGRAPH_H

#include <string>
#include <vector>

const int MAX_NO_OF_STATES = 20;

class MidwestGraph
{
public:
	// Constructors
	MidwestGraph();
	MidwestGraph(int cap);

	// Copy contructor
	MidwestGraph(const MidwestGraph& other);

	// Declaration of overloaded assignment operator
	MidwestGraph& operator=(const MidwestGraph& other);

	// Declaration of function createGraph
	void createGraph(const std::vector<std::string>& v1, 
		const std::vector<std::vector<int>>& v2);

	// Declarations of all print functions
	void printStates() const;
	void printBorderingStates(const std::string& state) const;
	void printBFS(const std::string& states) const;
	
	// Destructor
	~MidwestGraph();

private:

	std::string *states;	//will point to a dynamic array storing labels for states
    int **borders;			//will point to a dynamic array of pointers to dynamic arrays
    int maxNoOfStates;		//max number of states the graph can hold (capacity)
    int numOfStates;		//total number of states
};

#endif