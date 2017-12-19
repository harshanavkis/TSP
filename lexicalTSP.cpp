#include "graph.h"

int main(int argc, char const *argv[])
{
	int v = 5;
	int e = 5;
	Graph *G = new Graph(v,e);
	std::cout<< G->getNumVertices() <<" "<< G->getNumEdges()<< std::endl;
	return 0;
}