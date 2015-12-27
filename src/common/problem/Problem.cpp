#include "problem/Problem.hpp"

void Problem::init(GenerationModel * model, int hierarchyDepth, int * levels, bool coevolutionary) {
	this->getFunctions(hierarchyDepth);
	switch(hierarchyDepth) {
		case 1:
			experiment = new ClassicalExperiment(objective, objectiveTS, promise, promiseTS, model);
			break;
		case 2:
			experiment = new TwoLevelExperiment(objective, objectiveTS, promise, promiseTS, model, levels[0], levels[1], coevolutionary);
			break;
		case 3:
			experiment = new ThreeLevelExperiment(objective, objectiveTS, promise, promiseTS, model, levels[0], levels[1], levels[2], coevolutionary);
			break;
		case 4:
			experiment = new FourLevelExperiment(objective, objectiveTS, promise, promiseTS, model, levels[0], levels[1], levels[2], levels[3], coevolutionary);
			break;
		case 5:
			experiment = new FiveLevelExperiment(objective, objectiveTS, promise, promiseTS, model, levels[0], levels[1], levels[2], levels[3], levels[4], coevolutionary);
			break;
	}
}

void Problem::run() {
	experiment->run();
}

