#include "problem/AverageFragProblem.hpp"
#include "experiment/Experiment.hpp"
#include "AverageFrag/AverageFrag.hpp"

void AverageFragProblem::getFunctions(int hierarchyDepth) {
	promise = new AverageFragFitness();
	promiseTS = new AverageFragToString();
	if (hierarchyDepth > 1) {
		objective = new HierAverageFragFitness();
		objectiveTS = new HierAverageFragToString();
	} else {
		objective = promise;
		objectiveTS = promiseTS;
	}
}

AverageFragProblem::AverageFragProblem(GenerationModel * model, int libraries) {
	init(model, 1, NULL, false);
}

AverageFragProblem::AverageFragProblem(GenerationModel * model, int secondLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, libraries};
	init(model, 2, levels, coevolutionary);
}

AverageFragProblem::AverageFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, libraries};
	init(model, 3, levels, coevolutionary);
}

AverageFragProblem::AverageFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, libraries};
	init(model, 4, levels, coevolutionary);
}

AverageFragProblem::AverageFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int fifthLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, fifthLevelNodes, libraries};
	init(model, 5, levels, coevolutionary);
}
