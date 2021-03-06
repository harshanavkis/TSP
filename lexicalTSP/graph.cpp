#include "graph.h"

Graph::Graph(const int v, const int e)
{
	V = v;
	E = e;
	adjList.reserve(this->V);

	std::cout<< "Enter the pair of vertices forming an edge and the length of the edge" << std::endl;

	for(int i=0; i<E; i++)
	{
		int u, v, len;
		std::cin>> u >> v >> len;
		addEdge(u, v, len, adjList);
	}
}

void Graph::addEdge(int u, int v,int len, std::vector<std::vector<Node>> &adjList)
{
	//for undirected graphs
	Node a;
	a.vertex = v;
	a.length = len;
	Node b;
	b.vertex = u;
	b.length = len;
	adjList[u].push_back(a);
	adjList[v].push_back(b);
}

int Graph::getNumVertices()
{
	return V;
}

int Graph::getNumEdges()
{
	return E;
}

int Graph::getEdgeLength(int u, int v)
{
	//return length of edge from u to v
	// std::vector<Node> vec = adjList[u];
	std::vector<Node>::iterator it;
	for(it=adjList[u].begin(); it!=adjList[u].end(); it++)
	{
		if(it->vertex == v)
			return it->length;
	}
}