#ifndef POPULATION_H
#define POPULATION_H

#include "DNA.h"
#include "graph.h"
#include <iostream>

class Population
{
public:
	Population(Graph G, int popSize, auto rng);
	Population(Graph G, int popSize)
	~Population();
	int maxFitMember();	
	DNA pickParent();
	void printMaxFit();


private:
	Graph G;
	DNA* generation;
	int popSize;
	
};

#endif