#ifndef DHA_H
#define DNA_H

#include <random>
#include <cmath>
#include <algorithm>

class DNA
{
public:
	DNA(){}
	DNA(int length);
	int length();
	void setProb(float prob);
	void setFitness(float fitness);
	float getProb();
	float getFitness();
	int getVertex(int index);
	void mutate(float mutationRate);
	DNA crossover(DNA partner);
	int* genes;
	~DNA(){}
private:
	int geneLength;
	float fitness;
	float prob;
};

#endif