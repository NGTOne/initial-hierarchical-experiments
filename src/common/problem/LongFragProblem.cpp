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
