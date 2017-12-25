#include "graph.h"
#include <fstream>

Graph::Graph(const std::string& fileName)
{
	int x;
	std::ifstream inFile;
	inFile.open(fileName);
	std::vector<int> c;
	while(inFile >> x)
	{
		c.push_back(x);
	}
	this->V = c[0];
	this->E = c[1];
	adjList.reserve(this->V);

	for(int i=2; i<c.size(); i+=3)
	{
		int u = c[i];
		int v = c[i+1];
		int len = c[i+2];
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