#include "experiment/ThreeLevelExperiment.hpp"

ThreeLevelExperiment::ThreeLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int midLevelPools, int bottomLevelPools, int libraryPools) {
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
			bottomNodes[k] = new HierarchicalGenePool(libraryPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
		}

		templateIndividual = new Individual(bottomNodes, bottomLevelPools, crossover, mutation, objective, objectiveTS);
		midNodes[i] = new HierarchicalGenePool(bottomLevelPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
	}


	templateIndividual = new Individual(midNodes, midLevelPools, crossover, mutation, objective, objectiveTS);

	topLevelPool = new HierarchicalGenePool(midLevelPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
}
