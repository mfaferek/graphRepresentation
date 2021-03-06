// GraphLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Graph.h"

struct DummyEdge {};
struct DummyVertex {};

struct CustomVertex
{
	int level;
	int parent;
};

struct CustomEdge
{
	int reverse;
};

int main()
{
	int numberOfVertices, numberOfEdges;
	int startPoint;
	int begin, end;

	std::cin >> numberOfVertices >> numberOfEdges >> startPoint;
	
	Graph<CustomVertex, CustomEdge> graph(numberOfVertices);

	for (int i = 0; i < numberOfEdges; ++i)
	{
		std::cin >> begin >> end;
		graph.addUndirectedEdge(begin, end);
	}

	std::cout << "Processed graph: " << std::endl;
	graph.write();

	graph.bfs(startPoint);


	for (int i = 0; i < numberOfVertices; ++i)
	{
		std::cout << "Vertex: " << i << ": level = " << graph.vertices[i].level <<
			", parent in BFS tree = " << graph.vertices[i].parent << std::endl;
	}

	std::cin >> begin;


    return 0;
}

