#include "experiment/TwoLevelExperiment.hpp"

TwoLevelExperiment::TwoLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int bottomLevelPools, int libraryPools) {
	CrossoverOperation * crossover = new NPointCrossover(2);
	MutationOperation * mutation = new UniformMutation(0.1);

	// Set up the library nodes
	int * bits = (int*)malloc(sizeof(int)*2);
	bits[0] = 0;
	bits[1] = 1;
	GenePool * baseGenes = new LibraryNode<int>(bits, 2);
	GenePool ** libraries = (GenePool**)malloc(sizeof(GenePool*)*libraryPools);
	for (int i = 0; i < libraryPools; i++) libraries[i] = baseGenes;

	Individual * templateIndividual = new Individual(libraries, libraryPools, crossover, mutation, promise, promiseTS);

	GenePool ** bottomPopNodes = (GenePool**)malloc(sizeof(GenePool*)*bottomLevelPools);
	for (int i = 0; i < bottomLevelPools; i++) bottomPopNodes[i] = new HierarchicalGenePool(libraryPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());

	templateIndividual = new Individual(bottomPopNodes, bottomLevelPools, crossover, mutation, objective, objectiveTS);

	topLevelPool = new HierarchicalGenePool(bottomLevelPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
}
