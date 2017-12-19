#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include <iostream>


class Graph
{
public:
	Graph(const int V, const int E);
	int getNumVertices();
	int getNumEdges();
	~Graph();

private:
	int V, E;
	std::vector<std::vector<int>> adjList;
	void addEdge(int u, int v, std::vector<std::vector<int>> &adjList);
	
};

#endif