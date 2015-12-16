#include "problem/LongFragProblem.hpp"
#include "experiment/Experiment.hpp"
#include "LongFrag/LongFrag.hpp"

void LongFragProblem::getFunctions(int hierarchyDepth) {
	FitnessFunction * promise = new LongFragFitness();
	ToStringFunction * promiseTS = new LongFragToString();
	FitnessFunction * objective;
	ToStringFunction * objectiveTS;
	if (hierarchyDepth > 1) {
		objective = new HierLongFragFitness();
		objectiveTS = new HierLongFragToString();
	} else {
		objective = promise;
		objectiveTS = promiseTS;
	}
}

LongFragProblem::LongFragProblem(GenerationModel * model, int libraries) {
	init(model, 1, NULL);
}

LongFragProblem::LongFragProblem(GenerationModel * model, int secondLevelNodes, int libraries) {
	int levels[] = {secondLevelNodes, libraries};
	init(model, 2, levels);
}

LongFragProblem::LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, libraries};
	init(model, 3, levels);
}

LongFragProblem::LongFragProblem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, libraries};
	init(model, 4, levels);
}
