#include "experiment/TwoLevelExperiment.hpp"

TwoLevelExperiment::TwoLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model) {
	CrossoverOperation * crossover = new NPointCrossover(2);
	MutationOperation * mutation = new UniformMutation(0.1);

	// Set up the library nodes
	int bits[] = {0, 1};
	GenePool * baseGenes = new NonHierarchicalGenePool<int>(bits, 2);
	GenePool ** libraries = (GenePool**)malloc(sizeof(GenePool*)*8);
	for (int i = 0; i < 8; i++) libraries[i] = baseGenes;

	Individual * templateIndividual = new Individual(libraries, 8, crossover, mutation, promise, promiseTS);

	GenePool ** bottomPopNodes = (GenePool**)malloc(sizeof(GenePool*)*4);
	for (int i = 0; i < 4; i++) bottomPopNodes[i] = new HierarchicalGenePool(16, templateIndividual, 100, 1, model, NULL, new NonPropagator());

	templateIndividual = new Individual(bottomPopNodes, 4, crossover, mutation, objective, objectiveTS);

	topLevelPool = new HierarchicalGenePool(8, templateIndividual, 100, 1, model, NULL, new NonPropagator());
}
