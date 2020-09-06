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
	states = new string[MAX_NO_OF_STATES];
	borders = new int* [MAX_NO_OF_STATES];

	for (int row = 0; row < MAX_NO_OF_STATES; ++row)
	{
		borders[row] = new int[MAX_NO_OF_STATES];
	}

	maxNoOfStates = MAX_NO_OF_STATES;		
	numOfStates = 0;		
}

// Overloaded constructor
MidwestGraph::MidwestGraph(int cap)
{
	states = new string[cap];
	borders = new int* [cap];
	for (int row = 0; row < cap; ++row)
	{
		borders[row] = new int[cap];
	}

	maxNoOfStates = cap;		
	numOfStates = 0;
}

// Copy constructor
//MidwestGraph::MidwestGraph(const MidwestGraph& other)
//{
//	states = other.states;
//	borders = other.borders;
//	maxNoOfStates = MAX_NO_OF_STATES;
//	numOfStates = other.numOfStates;

//	for (int i = 0; i < numOfStates; ++i)
//	{
//		states[i] = other.states[i];
//		borders[i] = other.borders[i];
//	}
//}

MidwestGraph::MidwestGraph(const MidwestGraph& other)
{

	for (int i = 0; i < maxNoOfStates; ++i)
	{
		states[i] = other.states[i];
		for (int j = 0; j < maxNoOfStates; ++j)
		{
			borders[i][j] = other.borders[i][j];
		}
	}
	

	maxNoOfStates = other.maxNoOfStates;
	numOfStates = other.numOfStates;
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
		if (maxNoOfStates != other.maxNoOfStates)
		{
			delete[] states;
			delete[] borders;
			states = new string[other.maxNoOfStates];
			maxNoOfStates = other.maxNoOfStates;
			// borders = new int*[other.numOfStates];
		}

		//maxNoOfStates = other.maxNoOfStates;
		//states = other.states;

		for (int i = 0; i < other.numOfStates; ++i)
		{
			states[i] = other.states[i];
			for (int j = 0; j < other.numOfStates; ++j)
			{
				borders[i][j] = other.borders[i][j];
			}
		}

		numOfStates = other.numOfStates;
	}

	return *this;
}

// Definition of function createGraph
void MidwestGraph::createGraph(const vector<string>& otherStates,
	const vector<vector<int>>& otherNeighbors)
{

	for (int i = 0; i < maxNoOfStates; i++)
	{
		states[i] = otherStates[i];				// transfers labels
		for (int j = 0; j < maxNoOfStates; ++j)
		{
			borders[i][j] = otherNeighbors[i][j];	// transfers edge data
		}
	}
}



// Definition of function printStates
// Assume there is at least one state.
void MidwestGraph::printStates() const
{
	for (int i = 0; i < maxNoOfStates; ++i)
	{
		cout << "      " << states[i] << endl;
	}
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

MidwestGraph::~MidwestGraph()
{
	delete[] states, delete[] borders;
	states = nullptr, borders = nullptr;
}