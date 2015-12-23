#include "experiment/ClassicalExperiment.hpp"

ClassicalExperiment::ClassicalExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model) {
	CrossoverOperation * crossover = new NPointCrossover(2);
	MutationOperation * mutation = new UniformMutation(0.1);

	// Set up the library nodes
	int * bits = (int*)malloc(sizeof(int)*2);
	bits[0] = 0;
	bits[1] = 1;
	GenePool * baseGenes = new LibraryNode<int>(bits, 2);
	GenePool ** libraries = (GenePool**)malloc(sizeof(GenePool*)*32);
	for (int i = 0; i < 32; i++) libraries[i] = baseGenes;

	Individual * templateIndividual = new Individual(libraries, 32, crossover, mutation, objective, objectiveTS);

	FitnessPropagator * propagator = new NonPropagator();

	topLevelPool = new HierarchicalGenePool(64, templateIndividual, 100, 1, model, NULL, propagator);

	delete(templateIndividual);
}
