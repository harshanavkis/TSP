#include "Population.h"

float calcGraphWeight(Graph G, DNA member)
{
	int weight = 0;
	for(int i=0; i<member.length(); i++)
	{
		int u = member.getVertex(i);
		int v = member.getVertex(i+1);
		weight += G.getEdgeLength(u, v);
	}
	return weight;
}

Population::Population(Graph G, int popSize, auto rng)
{
	this->generation = new DNA[popSize];
	this->G = G;
	for(int i=0; i<popSize; i++)
	{
		generation[i] = DNA(G.getNumVertices(), rng);
	}
}

Population::Population(Graph G, int popSize)
{
	this->generation = new DNA[popSize];
	this->G = G;
}

int Population::maxFitMember()
{
	float maxFitness = thihs->generation[0].getFitness();
	int index = 0;
	for(int i=0; i<this->popSize; i++)
	{
		if(maxFitness < this->generation(i).getFitness())
		{
			maxFitness = this->generation(i).getFitness();
			index = i;
		}
	}
	return index;
}

void Population::printMaxFit()
{
	int index = maxFitMember();
	DNA* m = this->generation[index];
	int length = this->generation[index].length();
	for(int i=0; i<length; i++)
	{
		std::cout << m[i] << "-->";
	}
	std::cout<< std::endl;
}

DNA Population::pickParent()
{
	float r = ((double)rand()/(RAND_MAX));
	DNA parent;
	for(int i=0; i<this->popSize; i++)
	{
		float prob = this->generation[i].getProb();
		if(r < prob)
		{
			return this->generation[i];
		}
	}
}

float Population::calcFitness()
{
	float totalFitness = 0;
	for(int i=0; i<this->popSize; i++)
	{
		float weight = calcGraphWeight(this->G, this->generation[i]);
		this->generation[i].setFitness(1.0/weight);
		totalFitness += (1.0/weight);
	}
	return totalFitness;
}

void getProbVals(float totalFitness)
{
	for(int i=0; i<this->popSize; i++)
	{
		this->generation[i].setProb(this->generation[i].getFitness()/totalFitness);
	}
}

void Population::addChild(DNA child, int index)
{
	this->generation[index] = child;
}

Population Population::nextGeneration()
{
	Population nextGen = Population(this->G, this->popSize);
	float totalFitness = this->calcFitness();
	this->getProbVals(totalFitness);
	for(int i=0; i<this->popSize; i++)
	{
		DNA parentA = pickParent();
		DNA parentB = pickParent();
		DNA child = parentA.crossover(parentB);
		child.mutate(0.01);
		nextGen .addChild(child, i);
	}
}