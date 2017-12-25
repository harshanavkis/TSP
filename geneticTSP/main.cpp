#include "Population.h"

int main(int argc, char const *argv[])
{
	auto rng = std::default_random_engine {}; //to generate random shuffle
	const std::string = "testGraph.txt";
	Graph G = Graph(fileName);

	int popSize;
	float mutationRate;
	std::cout << "Enter the population size:" << std::endl;
	std::cin >> popSize;
	std::cout << "Enter the mutation rate:" << std::endl;
	std::cin >> mutationRate;

	Population population = Population(G, popSize, rng);


	return 0;
}
