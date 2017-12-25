#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include <iostream>
#include <string>



// class Node
// {
// public:
// 	Node(const int v, const int len)
// 	{
// 		vertex = v;
// 		length = len;
// 	}
// 	int getVertex()
// 	{
// 		return vertex;
// 	}
// 	int getLength()
// 	{
// 		return length;
// 	}
// private:
// 	int vertex;
// 	int length;
// };

struct Node
{
	int vertex, length;
};

class Graph
{
public:
	Graph(){}
	Graph(const std::string& fileName);
	int getNumVertices();
	int getNumEdges();
	int getEdgeLength(int u, int v);
	~Graph(){}

private:
	int V, E;
	std::vector<std::vector<Node>> adjList;
	void addEdge(int u, int v, int len, std::vector<std::vector<Node>> &adjList);
	
};

#endif