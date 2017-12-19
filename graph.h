#ifndef GRAPH_H

#define GRAPH_H

#include <vector>

class GRAPH
{
public:
	GRAPH(const int V, const int E);
	~GRAPH(){}

private:
	int V, E;
	std::vector<std::vector<int>> adjList;
	void addEdge(int u, int v, std::vector<std::vector<int>> &adjList);
	
};

#endif