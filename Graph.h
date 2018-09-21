#pragma once
#include <vector>
#include <queue>
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

	void bfs(int startPoint)
	{
		for (auto& it : vertices)
		{
			it.level = -1;
			it.parent = -1;
		}

		vertices[startPoint].level = 0;
		std::queue<int> buffor;
		//int begin = 0;
		//int end = 0;
		buffor.push(startPoint);

		while (!buffor.empty())
		{
			startPoint = buffor.front();
			buffor.pop();

			for (auto& it : vertices[startPoint])
			{
				if (vertices[it.vertex].level == -1)
				{
					vertices[it.vertex].level = vertices[startPoint].level + 1;
					vertices[it.vertex].parent = startPoint;
					buffor.push(it.vertex);
				}
			}
		}
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

