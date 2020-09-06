/*
	Blood, William

	September 2, 2020

	CS A200
	Lab 1
*/

#include "MidwestGraph.h"

#include <iostream>
#include <queue>
using namespace std;

// Default constructor
MidwestGraph::MidwestGraph() 
{
	states = new string[];
	borders = new int* [] {0};
	maxNoOfStates = MAX_NO_OF_STATES;		
	numOfStates = 0;		
}

// Overloaded constructor
MidwestGraph::MidwestGraph(int cap)
{
	states = new string[]{ 0 };
	borders = new int* [] {0};
	maxNoOfStates = MAX_NO_OF_STATES;		
	numOfStates = cap;		
}

// Copy constructor
MidwestGraph::MidwestGraph(const MidwestGraph& other)
{
	states = other.states;
	borders = other.borders;
	maxNoOfStates = MAX_NO_OF_STATES;
	numOfStates = other.numOfStates;

	for (int i = 0; i < numOfStates; ++i)
	{
		borders[i] = other.borders[i];
	}
}

// Definition of overloaded assignment operator
MidwestGraph& MidwestGraph::operator=(const MidwestGraph& other)
{
	if (&other == this)
	{
		cerr << "Attempted self-assignment";
	}
	else
	{
		if (numOfStates != other.numOfStates)
		{
			delete[] borders;
			borders = new int*[other.numOfStates];
		}

		numOfStates = other.numOfStates;
		maxNoOfStates = other.maxNoOfStates;
		states = other.states;

		for (int i = 0; i < maxNoOfStates; ++i)
		{
			borders[i] = other.borders[i];
		}
	}

	return *this;
}

// Definition of function createGraph
void MidwestGraph::createGraph(const vector<string>& otherStates,
	const vector<vector<int>>& otherNeighbors)
{
	for (int i = 0; i < numOfStates; i++)
	{
		states[i] = otherStates[i];		// Transfers state data
		
		for (int j = 0; j < numOfStates; j++)
		{
			borders[i][j] = otherNeighbors[i][j];	// Transfers edge data
		}
	}
}



// Definition of function printStates
// Assume there is at least one state.
void MidwestGraph::printStates() const
{
	cout << "printStates() called" << endl;
}

// Definition of function printBorderingStates
void MidwestGraph::printBorderingStates(const std::string& state) const
{
	cout << "printBorderingStates() called" << endl;
}

// Assume the array of strings has at list one state.
// Assume the given state is in the array of strings.
// Assume the given state has at least one neighbor.

// Definition of function printBFS
void MidwestGraph::printBFS(const std::string& states) const
{
	cout << "printBFS() called" << endl;
}

// Destructor

MidwestGraph::~MidwestGraph(){}