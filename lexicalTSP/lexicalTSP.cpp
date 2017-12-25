#include "graph.h"
#include <algorithm>

bool nextLexical(std::vector<int> &currentOrder, int len);
void reverse(std::vector<int> &vertices, int startIndex);
int pathLength(std::vector<int> path, int len, int source, Graph* G);
void swap(std::vector<int> &currentOrder, int startIndex, int endIndex);
void printPath(std::vector<int> path, int len);


int main(int argc, char const *argv[])
{
	int v, e; //number of vertices and edges
	std::cin >> v >> e;
	int source;
	std::cout<< "Enter the source vertex" << std::endl;
	std::cin >> source;
	Graph* G = new Graph(v, e);

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
	// int lexOrder[v];
	// lexOrder[0] = source; //assuming initial path order is lexicographical order
	// for(int i=1; i<v; i++)
	// {
	// 	lexOrder[i] = path[i];
	// }

	bestLen = pathLength(path, v, source, G);
	std::cout << "Current Best Length: "<< bestLen <<";" << "Path is:" ;
	printPath(path , v) ;
	std::cout<< source << std::endl;

	while(nextLexical(path, v))
	{
		if(bestLen > pathLength(path, v, source, G))
		{
			bestLen = pathLength(path, v, source, G);
			std::cout << "Current Best Length: "<< bestLen <<";" << "Path is:" ;
			printPath(path , v) ;
			std::cout<< source << std::endl;
		}
	}
	return 0;
}


bool nextLexical(std::vector<int> &currentOrder, int len)
{
	//misof's algorithm
	int x=-1, y;
	int Px, Py;
	for(int i=1; i<len-1; i++)
	{
		if(currentOrder[i] < currentOrder[i+1])
		{
			x = i;
			Px = currentOrder[i];
		}
	}
	if(x==-1)
		return false;
	for(int i=1; i<len; i++)
	{
		if(currentOrder[i] > Px)
			y = i;
			Py = currentOrder[i];
	}
	swap(currentOrder, x, y);
	reverse(currentOrder, x+1);
	return true;
}

void swap(std::vector<int> &currentOrder, int startIndex, int endIndex)
{
	int temp = currentOrder[startIndex];
	currentOrder[startIndex] = currentOrder[endIndex];
	currentOrder[endIndex] = temp; 
}

void reverse(std::vector<int> &currentOrder, int startIndex)
{
	std::vector<int>::iterator s = currentOrder.begin() + startIndex;
	std::reverse(s, currentOrder.end());
}

int pathLength(std::vector<int> path, int len, int source, Graph* G)
{
	int size = 0;
	for(int i=0; i<len-1; i++)
	{
		size+=G->getEdgeLength(path[i], path[i+1]);
	}
	size+=G->getEdgeLength(path[len-1], source);
	return size;
}

void printPath(std::vector<int> path, int len)
{
	for(int i=0; i<len; i++)
	{
		std::cout<< path[i] << "->";
	}
}

/*
0 1 10                                                                                                                               
0 2 15                                                                                                                               
0 3 20                                                                                                                               
1 2 35                                                                                                                               
1 3 25                                                                                                                               
2 3 30 
*/