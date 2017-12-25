#ifndef DHA_H
#define DNA_H

#include <random>
#include <cmath>
#include <algorithm>
#include "graph.h"

class DNA
{
public:
	DNA(int length);
	void setProb(float prob);
	void setFitness(float fitness);
	float getProb();
	float getFitness();
	~DNA();
private:
	int* genes;
	int geneLength;
	float fitness;
	float prob;
};

#endif