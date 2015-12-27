#include "problem/LongFragProblem.hpp"
#include "experiment/Experiment.hpp"
#include "LongFrag/LongFrag.hpp"

void LongFragProblem::getFunctions(int hierarchyDepth) {
	promise = new LongFragFitness();
	promiseTS = new LongFragToString();
	if (hierarchyDepth > 1) {
		objective = new HierLongFragFitness();
		objectiveTS = new HierLongFragToString();
	} else {
		objective = promise;
		objectiveTS = promiseTS;
	}
}

LongFragProblem::LongFragProblem(GenerationModel * model, int libraries) {
	init(model, 1, NULL, false);
}

LongFragProblem::LongFragProblem(GenerationModel * model, int secondLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, libraries};
	init(model, 2, levels, coevolutionary);
}

LongFragProblem::LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, libraries};
	init(model, 3, levels, coevolutionary);
}

LongFragProblem::LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, libraries};
	init(model, 4, levels, coevolutionary);
}

LongFragProblem::LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int fifthLevelNodes, int libraries, bool coevolutionary) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, fifthLevelNodes, libraries};
	init(model, 5, levels, coevolutionary);
}
