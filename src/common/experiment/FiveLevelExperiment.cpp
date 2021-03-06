#include "experiment/FiveLevelExperiment.hpp"

FiveLevelExperiment::FiveLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int secondLevelPools, int thirdLevelPools, int fourthLevelPools, int bottomLevelPools, int libraryPools, bool coevolutionary) {
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
			GenePool ** levelFourPools = (GenePool**)malloc(sizeof(GenePool*)*fourthLevelPools);

			for (int c = 0; c < fourthLevelPools; c++) {
				GenePool ** bottomPools = (GenePool**)malloc(sizeof(GenePool*)*bottomLevelPools);
				templateIndividual = new Individual(libraries, libraryPools, crossover, mutation, promise, promiseTS);

				for (int a = 0; a < bottomLevelPools; a++) {
					// If we don't set the bottom level
					// pools to evolve, nothing will happen!
					bottomPools[a] = getNode(libraryPools, false);
				}

				templateIndividual = new Individual(bottomPools, bottomLevelPools, crossover, mutation, objective, objectiveTS);

				levelFourPools[c] = getNode(bottomLevelPools, coevolutionary);
			}

			templateIndividual = new Individual(levelFourPools, fourthLevelPools, crossover, mutation, objective, objectiveTS);

			levelThreePools[k] = getNode(fourthLevelPools, coevolutionary);
		}

		templateIndividual = new Individual(levelThreePools, thirdLevelPools, crossover, mutation, objective, objectiveTS);

		levelTwoPools[i] = getNode(thirdLevelPools, coevolutionary);
	}

	templateIndividual = new Individual(levelTwoPools, secondLevelPools, crossover, mutation, objective, objectiveTS);

	topLevelPool = getNode(secondLevelPools, coevolutionary);
}
