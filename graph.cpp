#include "graph.h"

Graph::Graph(const int V, const int E)
{
	this->V = V;
	this->E = E;
	this->adjList.reserve(this->V);

	std::cout<< "Enter the pair of vertices forming an edge." << std::endl;

	for(int i=0; i<this->V; i++)
	{
		int u, v;
		std::cin>> u >> v; 
		addEdge(u, v, adjList);
	}
}

void Graph::addEdge(const int u, const int v, std::vector<std::vector<int>> &adjList)
{
	//for undirected graphs
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}