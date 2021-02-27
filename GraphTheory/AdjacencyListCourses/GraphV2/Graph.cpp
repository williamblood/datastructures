/*
	Blood, William

	February 13, 2021

	CS A200
	Lab 1
*/

#include "Graph.h"

using namespace std;

// Definition function operator<<
ostream& operator<<(ostream& out, const Graph& rhs)	
{
	auto iter = rhs.graph->begin(),
		iterEnd = rhs.graph->end();

	for (iter; iter != iterEnd; iter++)
	{
		out << COURSE_PREFIX << iter->first << ": ";

		set<int>& prereqs = iter->second;
		if (prereqs.empty())
			out << "No prerequisites.";
		else
		{
			for (int i : prereqs)
			{
				out << COURSE_PREFIX << i << " ";
			}
		}
		out << endl;
	}
	return out;
}

// Definition default constructor
Graph::Graph()
{
	graph = new map<int, set<int>>;
	numOfCourses = 0;
}

// Definition copy constructor
// Add "noexcept" at the end of the header.
Graph::Graph(const Graph& other) noexcept
{
	int otherCapacity = 
		static_cast<int>(other.graph->size());

	graph = new map<int, set<int>>[otherCapacity];
	numOfCourses = other.numOfCourses;
}

// Add "noexcept" at the end of the header.
Graph& Graph::operator=(const Graph& other) noexcept
{
	if (this == &other)
	{
		cerr << "Attempted self-assignment";
	}
	else
	{
		if (numOfCourses != other.numOfCourses)
		{
			int otherCapacity = 
				static_cast<int>(other.graph->size());

			graph->clear();									// release space
			graph = new map<int, set<int>>[otherCapacity];	// recreate map
			numOfCourses = other.numOfCourses;
		}
		// deep copy elements
		auto iter = other.graph->begin(),
			iterEnd = other.graph->end();

		for (iter; iter != iterEnd; ++iter)
		{
			int course = iter->first;
			set<int> preqrequisites = iter->second;

			graph->insert(make_pair(course, preqrequisites));
		}
	}
	return *this;
}

// Definition destructor
Graph::~Graph()
{
	clearGraph();
	graph = nullptr;
}

// Definition function createGraph
void Graph::createGraph(const vector<vector<int>>& graphData)
{
	for (const vector<int>& courses : graphData)
	{
		int key = courses[0];

		set<int> prereqs;
		for (auto course : courses)
		{
			if (key != course) 
			{
				prereqs.insert(course);
			}
		}
		graph->insert(make_pair(key, prereqs));
		numOfCourses++;
	}
}

// Definition function isEmpty
bool Graph::isEmpty() const
{
	return (numOfCourses == 0);
}

// Definition function printAllCourses
void Graph::printAllCourses() const
{
	auto iter = graph->begin(),
		iterEnd = graph->end();
	
	for (iter; iter != iterEnd; iter++)
	{
		cout << COURSE_PREFIX << iter->first << endl;
	}
}

// Definition function printPrerequisites
void Graph::printPrerequisites(int course) const
{
	auto courseIter = graph->find(course);

	if (courseIter->second.empty())
	{
		cout << "No prerequisites.";
	}
	else
	{
		for (auto prerequisite : courseIter->second)
		{
			cout << prerequisite << " ";
		}
	}
}

// Definition function clearGraph
void Graph::clearGraph()
{
	graph->clear();
	numOfCourses = 0;
}
