#pragma once
#include <vector>
#include <iostream>

template<typename CustomVertex, typename CustomEdge>
struct Graph
{
	struct Edge : CustomEdge
	{
		int vertex;
		Edge(CustomEdge edge, int endVertex) :
			CustomEdge(edge), ////needs analyzis
			vertex(endVertex)
		{}
	};

	struct Vertex : CustomVertex, std::vector<Edge> {};

	std::vector<Vertex> vertices; //change to "graph"?

	Graph(int numberOfVertices) :
		vertices(numberOfVertices)
	{}

	~Graph() {}

	void addDirectedEdge(int begin, int end, CustomEdge edge = CustomEdge())
	{
		vertices[begin].push_back(Edge(edge, end));
	}

	void addUndirectedEdge(int begin, int end, CustomEdge edge = CustomEdge())
	{
		Edge baseDirection(edge, end);
		baseDirection.reverse = vertices[end].size() + (begin == end); //needs analyzis
		vertices[begin].push_back(baseDirection);
		baseDirection.reverse = vertices[baseDirection.vertex = begin].size() - 1;
		vertices[end].push_back(baseDirection);
	}

	void write()
	{
		for (int i = 0; i < vertices.size(); ++i)
		{
			std::cout << i << ":";
			for (const auto& it : vertices[i])
			{
				std::cout << " " << it.vertex;
			}
			std::cout << std::endl;
		}
	}
};

