#include "problem/1maxProblem.hpp"
#include "experiment/Experiment.hpp"
#include "1max/1max.hpp"

void OneMaxProblem::getFunctions(int hierarchyDepth) {
	promise = new OneMaxFitness();
	promiseTS = new OneMaxToString();
	if (hierarchyDepth > 1) {
		objective = new HierOneMaxFitness();
		objectiveTS = new HierOneMaxToString();
	} else {
		objective = promise;
		objectiveTS = promiseTS;
	}
}

OneMaxProblem::OneMaxProblem(GenerationModel * model, int libraries) {
	init(model, 1, NULL, false);
}

OneMaxProblem::OneMaxProblem(GenerationModel * model, int secondLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, libraries};
	init(model, 2, levels, coevolutionary);
}

OneMaxProblem::OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, libraries};
	init(model, 3, levels, coevolutionary);
}

OneMaxProblem::OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, libraries};
	init(model, 4, levels, coevolutionary);
}

OneMaxProblem::OneMaxProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int fifthLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, fifthLevelNodes, libraries};
	init(model, 5, levels, coevolutionary);
}
