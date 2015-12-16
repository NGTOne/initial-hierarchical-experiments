#include "problem/1maxProblem.hpp"
#include "experiment/Experiment.hpp"
#include "1max/1max.hpp"

void OneMaxProblem::getFunctions(int hierarchyDepth) {
	FitnessFunction * promise = new OneMaxFitness();
	ToStringFunction * promiseTS = new OneMaxToString();
	FitnessFunction * objective;
	ToStringFunction * objectiveTS;
	if (hierarchyDepth > 1) {
		objective = new HierOneMaxFitness();
		objectiveTS = new HierOneMaxToString();
	} else {
		objective = promise;
		objectiveTS = promiseTS;
	}
}
