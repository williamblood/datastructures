/*
	Blood, William

	February 13, 2021

	CS A200
	Lab 1
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

const std::string COURSE_PREFIX = "CS A";

class Graph
{
	// Declaration friend function operator<<
	friend std::ostream& operator<<(std::ostream&,
		const Graph&);

public:
	// Declaration default constructor
	Graph();

	// Declarations for the Big Three
	Graph(const Graph&) noexcept;				// copy constructor
	Graph& operator=(const Graph&) noexcept;	// overloaded assignment operator

	// Declaration function createGraph
	void createGraph(const std::vector<std::vector<int>>&);

	// Declaration function isEmpty
	bool isEmpty() const;

	// Declarations of print functions
	void printAllCourses() const;
	void printPrerequisites(int ) const;

	// Declaration function clearGraph
	void clearGraph();

	// Destructor
	~Graph();

private:

	std::map<int, std::set<int>>* graph;
	int numOfCourses;
};

#endif