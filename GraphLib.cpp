// GraphLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Graph.h"

struct DummyEdge {};
struct DummyVertex {};

int main()
{
	int numberOfVertices, numberOfEdges;
	int begin, end;

	std::cin >> numberOfVertices >> numberOfEdges;

	Graph<DummyVertex, DummyEdge> graph(numberOfVertices);

	for (int i = 0; i < numberOfEdges; ++i)
	{
		std::cin >> begin >> end;
		graph.addDirectedEdge(begin, end);
	}

	graph.write();

	std::cin >> begin;

    return 0;
}

