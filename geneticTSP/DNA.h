#ifndef DHA_H
#define DNA_H

#include <random>
#include <cmath>
#include <algorithm>

class DNA
{
public:
	DNA(int length, auto rng);
	DNA(int length);
	int length();
	void setProb(float prob);
	void setFitness(float fitness);
	float getProb();
	float getFitness();
	void mutate(float mutationRate);
	DNA crossover(DNA partner);
	~DNA();
private:
	int* genes;
	int geneLength;
	float fitness;
	float prob;
};

#endif