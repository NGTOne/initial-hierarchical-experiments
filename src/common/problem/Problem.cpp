#include "problem/Problem.hpp"

void Problem::init(GenerationModel * model, int hierarchyDepth, int * levels) {
	getFunctions(hierarchyDepth);
	switch(hierarchyDepth) {
		case 1:
			experiment = new ClassicalExperiment(objective, objectiveTS, promise, promiseTS, model);
			break;
		case 2:
			experiment = new TwoLevelExperiment(objective, objectiveTS, promise, promiseTS, model, levels[0], levels[1]);
			break;
		case 3:
			experiment = new ThreeLevelExperiment(objective, objectiveTS, promise, promiseTS, model, levels[0], levels[1], levels[2]);
			break;
		case 4:
			experiment = new FourLevelExperiment(objective, objectiveTS, promise, promiseTS, model, levels[0], levels[1], levels[2], levels[3]);
			break;
	}
	
}

void Problem::run() {
	experiment->run();
}

Problem::Problem(GenerationModel * model, int libraries) {
	init(model, 1, NULL);
}

Problem::Problem(GenerationModel * model, int secondLevelNodes, int libraries) {
	int levels[] = {secondLevelNodes, libraries};
	init(model, 2, levels);
}

Problem::Problem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, libraries};
	init(model, 3, levels);
}

Problem::Problem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries) {
	int levels[] = {secondLevelNodes, thirdLevelNodes, fourthLevelNodes, libraries};
	init(model, 4, levels);
}
