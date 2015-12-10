#include "problem/LongFragProblem.hpp"
#include "experiment/Experiment.hpp"
#include "LongFrag/LongFrag.hpp"

LongFragProblem::LongFragProblem(GenerationModel * model, int hierarchyDepth) {
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

	switch(hierarchyDepth) {
		case 1:
			experiment = new ClassicalExperiment(objective, objectiveTS, promise, promiseTS, model);
		case 2:
			experiment = new TwoLevelExperiment(objective, objectiveTS, promise, promiseTS, model);
		case 3:
			experiment = new ThreeLevelExperiment(objective, objectiveTS, promise, promiseTS, model);
	}
}
