#ifndef POPULATION_H
#define POPULATION_H

#include "DNA.h"
#include "graph.h"
#include <iostream>

class Population
{
public:
	Population();
	Population(Graph G, int popSize);
	Population(int popSize, Graph G);
	~Population(){}
	int maxFitMember();	
	DNA pickParent();
	void printMaxFit();
	float calcFitness();
	Population nextGeneration();
	void getProbVals(float totalFitness);
	void addChild(DNA child, int index);


private:
	Graph G;
	DNA* generation;
	int popSize;
	
};

#endif