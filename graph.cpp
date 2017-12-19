#include "graph.h"

Graph::Graph(const int v, const int e)
{
	V = v;
	E = e;
	adjList.reserve(this->V);

	std::cout<< "Enter the pair of vertices forming an edge." << std::endl;

	for(int i=0; i<E; i++)
	{
		int u, v;
		std::cin>> u >> v; 
		addEdge(u, v, adjList);
	}
}

void Graph::addEdge(int u, int v, std::vector<std::vector<int>> &adjList)
{
	//for undirected graphs
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

int Graph::getNumVertices()
{
	return V;
}

int Graph::getNumEdges()
{
	return E;
}