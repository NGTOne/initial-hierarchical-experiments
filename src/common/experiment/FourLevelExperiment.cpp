#include "experiment/FourLevelExperiment.hpp"

FourLevelExperiment::FourLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int secondLevelPools, int thirdLevelPools, int bottomLevelPools, int libraryPools) {
	CrossoverOperation * crossover = new NPointCrossover(2);
	MutationOperation * mutation = new UniformMutation(0.1);

	// Set up the library nodes
	int * bits = (int*)malloc(sizeof(int)*2);
	bits[0] = 0;
	bits[1] = 1;
	GenePool * baseGenes = new LibraryNode<int>(bits, 2);
	GenePool ** libraries = (GenePool**)malloc(sizeof(GenePool*)*libraryPools);
	for (int i = 0; i < libraryPools; i++) libraries[i] = baseGenes;

	GenePool ** levelTwoPools = (GenePool**)malloc(sizeof(GenePool*)*secondLevelPools);

	Individual * templateIndividual;

	for (int i = 0; i < secondLevelPools; i++) {
		GenePool ** levelThreePools = (GenePool**)malloc(sizeof(GenePool*)*thirdLevelPools);

		for (int k = 0; k < thirdLevelPools; k++) {
			GenePool ** bottomPools = (GenePool**)malloc(sizeof(GenePool*)*bottomLevelPools);
			templateIndividual = new Individual(libraries, libraryPools, crossover, mutation, promise, promiseTS);

			for (int c = 0; c < bottomLevelPools; c++) {
				bottomPools[c] = new HierarchicalGenePool(libraryPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
			}

			templateIndividual = new Individual(bottomPools, bottomLevelPools, crossover, mutation, objective, objectiveTS);

			levelThreePools[k] = new HierarchicalGenePool(bottomLevelPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
		}

		templateIndividual = new Individual(levelThreePools, thirdLevelPools, crossover, mutation, objective, objectiveTS);

		levelTwoPools[i] = new HierarchicalGenePool(thirdLevelPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
	}

	templateIndividual = new Individual(levelTwoPools, secondLevelPools, crossover, mutation, objective, objectiveTS);

	topLevelPool = new HierarchicalGenePool(secondLevelPools*2, templateIndividual, 100, 1, model, NULL, new NonPropagator());
}
