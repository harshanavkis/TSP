#include "DNA.h"

int rangeRandomAlg(int min, int max)
{
	/*
		-Function to find random number from an unbiased distibution
		-function credits to: https://stackoverflow.com/questions/11758809/what-is-the-optimal-algorithm-for-generating-an-unbiased-random-integer-within-a?answertab=votes#tab-top
	*/
	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;
	do
	{
		x = rand();
	}while(x >= RAND_MAX - remainder);
	return min + x % n;
}

void shuffle(int* genes, int length)
{
	for(int i=0; i<length; i++)
	{
		int index = rangeRandomAlg(0, length);
		int temp = genes[index];
		genes[index] = genes[i];
		genes[i] = temp;
	}
}

DNA::DNA(int length)
{
	this->genes = new int[length];
	this->geneLength = length;
	for(int i=0; i<length; i++)
	{
		genes[i] = i;
	}
	shuffle(this->genes, length);
}


int DNA::length()
{
	return this->geneLength;
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

void DNA::mutate(float mutationRate)
{
	for(int i=0; i<this->geneLength; i++)
	{
		float r = ((double)rand()/(RAND_MAX));
		if(r<mutationRate)
		{
			int index = rangeRandomAlg(0, geneLength);
			int temp = this->genes[index];
			this->genes[index] = this->genes[i];
			this->genes[i] = temp;
		}
	}
}

DNA DNA::crossover(DNA partner)
{
	DNA child = DNA(partner.length());
	int midpoint = rangeRandomAlg(0, partner.length());

	for(int i=0; i<geneLength; i++)
	{
		if(i > midpoint) child.genes[i] = this->genes[i];
		else child.genes[i] = partner.genes[i];
	}
	return child;
}

int DNA::getVertex(int index)
{
	return this->genes[index];
}