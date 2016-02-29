#include <libHierGA/HierGA.hpp>
#include "experiment/Experiment.hpp"
#pragma once

#define runSilent (strcmp(argv[1], "silent")) ? false : true

class Problem {
	private:

	protected:
	HierExperiment * experiment;
	FitnessFunction * promise;
	FitnessFunction * objective;
	ToStringFunction * promiseTS;
	ToStringFunction * objectiveTS;
	void init(
		GenerationModel * model,
		int hierarchyDepth,
		int * levels,
		bool coevolutionary
	);
	virtual void getFunctions(int hierarchyDepth)=0;

	public:
	void run(bool silent);
};
