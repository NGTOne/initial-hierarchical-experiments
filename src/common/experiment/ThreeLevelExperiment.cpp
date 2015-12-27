#include "experiment/ThreeLevelExperiment.hpp"

ThreeLevelExperiment::ThreeLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int midLevelPools, int bottomLevelPools, int libraryPools, bool coevolutionary) {
	CrossoverOperation * crossover = new NPointCrossover(2);
	MutationOperation * mutation = new UniformMutation(0.1);

	// Set up the library nodes
	int * bits = (int*)malloc(sizeof(int)*2);
	bits[0] = 0;
	bits[1] = 1;
	GenePool * baseGenes = new LibraryNode<int>(bits, 2);
	GenePool ** libraries = (GenePool**)malloc(sizeof(GenePool*)*libraryPools);
	for (int i = 0; i < libraryPools; i++) libraries[i] = baseGenes;

	GenePool ** midNodes = (GenePool**)malloc(sizeof(GenePool*)*midLevelPools);
	Individual * templateIndividual;

	for (int i = 0; i < midLevelPools; i++) {
		templateIndividual = new Individual(libraries, libraryPools, crossover, mutation, promise, promiseTS);
		GenePool ** bottomNodes = (GenePool**)malloc(sizeof(GenePool*)*bottomLevelPools);
		for (int k = 0; k < bottomLevelPools; k++) {
			bottomNodes[k] = getNode(libraryPools, false);
		}

		templateIndividual = new Individual(bottomNodes, bottomLevelPools, crossover, mutation, objective, objectiveTS);
		midNodes[i] = getNode(bottomLevelPools, coevolutionary);
	}


	templateIndividual = new Individual(midNodes, midLevelPools, crossover, mutation, objective, objectiveTS);

	topLevelPool = getNode(midLevelPools, coevolutionary);
}
