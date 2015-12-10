#include "problem/1maxProblem.hpp"
#include "experiment/Experiment.hpp"
#include "1max/1max.hpp"

OneMaxProblem::OneMaxProblem(GenerationModel * model, int hierarchyDepth) {
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

	switch(hierarchyDepth) {
		case 1:
			experiment = new ClassicalExperiment(objective, objectiveTS, promise, promiseTS, model);
		case 2:
			experiment = new TwoLevelExperiment(objective, objectiveTS, promise, promiseTS, model);
		case 3:
			experiment = new ThreeLevelExperiment(objective, objectiveTS, promise, promiseTS, model);
	}
}
