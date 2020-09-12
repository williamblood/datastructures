/*
	Blood, William

	September 2, 2020

	CS A200
	Lab 1 - Graphs
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
	maxNoOfStates = MAX_NO_OF_STATES;
	numOfStates = 0;

	for (int row = 0; row < MAX_NO_OF_STATES; ++row)
	{
		borders[row] = new int[MAX_NO_OF_STATES];
		
		for (int column = 0; column < MAX_NO_OF_STATES; ++column)
			borders[row][column] = 0;
	}	
}

// Overloaded constructor
MidwestGraph::MidwestGraph(int capacity)
{
	states = new string[capacity];
	borders = new int* [capacity];
	maxNoOfStates = capacity;
	numOfStates = 0;

	for (int row = 0; row < capacity; ++row)
	{
		borders[row] = new int[capacity];

	}
}

// Copy constructor
MidwestGraph::MidwestGraph(const MidwestGraph& other)
{
	maxNoOfStates = other.maxNoOfStates;
	numOfStates = other.numOfStates;
	states = new string[maxNoOfStates];
	borders = new int* [maxNoOfStates];

	for (int i = 0; i < maxNoOfStates; ++i)
	{
		states[i] = other.states[i];
		borders[i] = new int[maxNoOfStates];

		for (int j = 0; j < maxNoOfStates; ++j)
		{
			borders[i][j] = other.borders[i][j];
		}
	}
}

// Definition of overloaded assignment operator
MidwestGraph& MidwestGraph::operator=(const MidwestGraph& rhs)
{
	if (&rhs == this)
	{
		cerr << "Attempted self-assignment";
	}
	else
	{
		if (maxNoOfStates != rhs.maxNoOfStates)
		{
			for (int i = 0; i < numOfStates; ++i)
			{
				delete[] borders[i]; 
				borders[i] = nullptr;
			}
	
			delete[] states;
			delete[] borders;

			states = new string[rhs.maxNoOfStates];
			maxNoOfStates = rhs.maxNoOfStates;
			borders = new int* [maxNoOfStates];
		}

		numOfStates = rhs.numOfStates;

		for (int i = 0; i < numOfStates; ++i)
		{
			states[i] = rhs.states[i];
			borders[i] = new int[numOfStates];

			for (int j = 0; j < numOfStates; ++j)
				borders[i][j] = rhs.borders[i][j];
		}

	}

	return *this;
}

// Definition of function createGraph
void MidwestGraph::createGraph(const vector<string>& otherStates,
	const vector<vector<int>>& otherNeighbors)
{
	numOfStates = static_cast<int>( otherStates.size() );

	for (int i = 0; i < numOfStates; i++)
	{
		states[i] = otherStates[i];					// transfers successor data
		
		for (int j = 0; j < numOfStates; ++j)
			borders[i][j] = otherNeighbors[i][j];	// transfers predecessor 
	}
}

// Definition of function printStates
// Assume there is at least one state.
void MidwestGraph::printStates() const
{
	for (int i = 0; i < maxNoOfStates; ++i)
		cout << "      " << states[i] << endl;
}

// Definition of function printBorderingStates
void MidwestGraph::printBorderingStates(const std::string& state) const
{
	int index = 0;

	// Finds index corresponding to the input state
	while (state != states[index])
		index++;

	for (int j = 0; j < numOfStates; j++)
	{
		if (borders[index][j])
			cout << states[j] << " ";
	}
}

// Assume the array of strings has at list one state.
// Assume the given state is in the array of strings.
// Assume the given state has at least one neighbor.
// Definition of function printBFS
void MidwestGraph::printBFS(const std::string& state) const
{
	int index = 0;			// Stores position of input state

	// Finds index of corresponding vertex.
	while (state != states[index])
		index++;

	 // Stores a record of visited nodes.
	bool* visited = new bool[numOfStates] { false };

	// Marks the starting vertex as visited & adds to queue.
	visited[index] = true;

	queue<int> borderingStates;
	borderingStates.push(index);

	// Enqueues all adjacent vertices corresponding to input vertex.
	while (!borderingStates.empty())
	{
		index = borderingStates.front();
		borderingStates.pop();

		for (int j = 0; j < maxNoOfStates; ++j)
		{
			if (!visited[j] && borders[index][j])
			{
				visited[j] = true;
				borderingStates.push(j);

				cout << states[j] << " ";
			}
		}
	}

	delete[] visited; visited = nullptr;
}

// Destructor
MidwestGraph::~MidwestGraph()
{
	// Frees each row
	for (int row = 0; row < numOfStates; ++row)
	{
		delete[] borders[row];
		borders[row] = nullptr;
	}
	delete[] states; states = nullptr;
	delete[] borders; borders = nullptr;
}