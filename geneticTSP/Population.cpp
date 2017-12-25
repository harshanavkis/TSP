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