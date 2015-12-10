#include "experiment/ThreeLevelExperiment.hpp"

ThreeLevelExperiment::ThreeLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model) {
	CrossoverOperation * crossover = new NPointCrossover(2);
	MutationOperation * mutation = new UniformMutation(0.1);

	// Set up the library nodes
	int * bits = (int*)malloc(sizeof(int)*2);
	bits[0] = 0;
	bits[1] = 1;
	GenePool * baseGenes = new NonHierarchicalGenePool<int>(bits, 2);
	GenePool ** libraries = (GenePool**)malloc(sizeof(GenePool*)*2);
	for (int i = 0; i < 2; i++) libraries[i] = baseGenes;

	GenePool ** midNodes = (GenePool**)malloc(sizeof(GenePool*)*4);
	Individual * templateIndividual;

	for (int i = 0; i < 4; i++) {
		templateIndividual = new Individual(libraries, 2, crossover, mutation, promise, promiseTS);
		GenePool ** bottomNodes = (GenePool**)malloc(sizeof(GenePool*)*4);
		for (int k = 0; k < 4; k++) {
			bottomNodes[k] = new HierarchicalGenePool(4, templateIndividual, 100, 1, model, NULL, new NonPropagator());
		}

		templateIndividual = new Individual(bottomNodes, 4, crossover, mutation, objective, objectiveTS);
		midNodes[i] = new HierarchicalGenePool(8, templateIndividual, 100, 1, model, NULL, new NonPropagator());
	}


	templateIndividual = new Individual(midNodes, 4, crossover, mutation, objective, objectiveTS);

	topLevelPool = new HierarchicalGenePool(8, templateIndividual, 100, 1, model, NULL, new NonPropagator());
}
