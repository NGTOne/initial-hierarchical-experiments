#include <libHierGA/HierGA.hpp>
#pragma once

class HierExperiment {
	private:

	protected:
	HierarchicalGenePool * topLevelPool;

	public:
	virtual HierExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model)=0;

	void run();
};
