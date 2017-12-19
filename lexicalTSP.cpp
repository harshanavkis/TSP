#include "graph.h"

bool nextLexical(int &currentOrder, int len);
void reverse(int &vertices, int startIndex, int endIndex);
int pathLength(int* path, int len)

int main(int argc, char const *argv[])
{
	int v, e; //number of vertices and edges
	Graph* G = new Graph(v, e);
	int source;
	std::cout<< "Enter the source vertex" << std::endl;

	//assuming all edge lengths are positive
	int bestLen = -1;
	std::vector<int> path;
	path.push_back(source);
	for(int i=0; i<v; i++)
	{
		if(i==source)
			continue;
		path.push_back(i); //assuming initial path is just the path of the vertices
	}
	int lexOrder[v];
	lexOrder[0] = source; //assuming initial path order is lexicographical order
	for(int i=1; i<v; i++)
	{
		lexOrder[i] = path[i];
	}

	bestLen = pathLength(path, v+1);

	while(nextLexical(path, v))
	{
		if(bestLen > pathLength(path))
			bestLen = pathLength(path);
		std::cout << "Current Best Length: "<< bestLen <<";" << "Path is:" <<printPath(path , v) <<" " << source << std::endl;
	}
	return 0;
}


bool nextLexical(int &currentOrder)
{
	
}