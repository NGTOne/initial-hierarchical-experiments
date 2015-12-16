#include <libHierGA/HierGA.hpp>
#include "experiment/Experiment.hpp"
#pragma once

class Problem {
	private:

	protected:
	HierExperiment * experiment;
	FitnessFunction * promise;
	FitnessFunction * objective;
	ToStringFunction * promiseTS;
	ToStringFunction * objectiveTS;
	void init(GenerationModel * model, int hierarchyDepth, int * levels);
	virtual void getFunctions(int hierarchyDepth)=0;

	public:
	void run();

	Problem(GenerationModel * model, int libraries);
	Problem(GenerationModel * model, int secondLevelNodes, int libraries);
	Problem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int libraries);
	Problem(GenerationModel * model, int secondLevelNodes, int thirdLevelNodes, int fourthLevelNodes, int libraries);
};
