#include "Population.h"

int main(int argc, char const *argv[])
{
	const std::string fileName = "testGraph.txt";
	Graph G = Graph(fileName);

	int popSize;
	float mutationRate;
	std::cout << "Enter the population size:" << std::endl;
	std::cin >> popSize;
	std::cout << "Enter the mutation rate:" << std::endl;
	std::cin >> mutationRate;

	Population population = Population(G, popSize);

	while(true)
	{
		population = population.nextGeneration();
		population.printMaxFit();
	}


	return 0;
}
