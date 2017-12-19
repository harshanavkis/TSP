#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include <iostream>


class Node
{
public:
	Node(const int v, const int len)
	{
		this.vertex = v;
		this.length = len;
	}
	int getVertex()
	{
		return vertex;
	}
	int getLength()
	{
		return length;
	}
private:
	int vertex;
	int length;
};

class Graph
{
public:
	Graph(const int V, const int E);
	int getNumVertices();
	int getNumEdges();
	~Graph();

private:
	int V, E;
	std::vector<std::vector<Node>> adjList;
	void addEdge(int u, int v, int len, std::vector<std::vector<Node>> &adjList);
	
};

#endif