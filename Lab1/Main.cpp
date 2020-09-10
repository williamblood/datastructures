/*
	Blood, William

	September 2, 2020

	CS A200
	Lab 1
*/

#include "MidwestGraph.h"

#include <iostream>
#include <vector>
#include <string>

void print(const MidwestGraph& graph, 
	const std::vector<std::string>& states);
void printBFS(const MidwestGraph& graph, 
	const std::vector<std::string>& states);

int main()
{
	std::vector<std::string> states = {
		"Illinois", "Indiana", "Iowa","Kansas",
		"Michigan", "Minnesota", "Missouri", "Nebraska",
		"North Dakota", "Ohio", "South Dakota", "Wisconsin"
	};

	std::vector<std::vector<int>> neighbors = {
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11
		{ 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, // Illinois
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 }, // Indiana
		{ 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1 }, // Iowa
		{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }, // Kansas
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 }, // Michigan
		{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1 }, // Minnesota
		{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, // Missouri
		{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0 }, // Nebraska
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 }, // North Dakota
		{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, // Ohio
		{ 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0 }, // South Dakota
		{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, // Wisconsin

	};

	MidwestGraph graph(12);
	graph.createGraph(states, neighbors);
	print(graph, states);
	printBFS(graph, states);

	std::cout << std::endl;
	return 0;
}

void print(const MidwestGraph& graph, 
	const std::vector<std::string>& states)
{
	std::cout << "STATES:\n";
	graph.printStates();

	std::cout << "\nNEIGHBORS:\n\n";
	for (const std::string& i : states)
	{
		std::cout << "   " << i << "\n";
		std::cout << "=> ";
		graph.printBorderingStates(i);	// prints bordering states per state
		std::cout << "\n";
	}
}

void printBFS(const MidwestGraph& graph, 
	const std::vector<std::string>& states)
{
	std::cout << "\nBFS:\n\n";
	for (const std::string& i : states)
	{
		std::cout << "   " << i << "\n";
		std::cout << "=> ";
		graph.printBFS(i);
		std::cout << "\n";
	}
}