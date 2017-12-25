#include "DNA.h"

DNA::DNA(int length, auto rng)
{
	this->genes = new int[length];
	this->geneLength = length;
	for(int i=0; i<length; i++)
	{
		genes[i] = i;
	}
	std::shuffle(this->genes, this->genes + length, rng);
}

void DNA::setProb(float prob)
{
	this->prob = prob;
}

void DNA::setFitness(float fitness)
{
	this->fitness = fitness;
}

float DNA::getProb()
{
	return this->prob;
}

float DNA::getFitness()
{
	return this->fitness;
}

