#include "experiment/HierExperiment.hpp"
#pragma once

class TwoLevelExperiment : public HierExperiment {
	private:

	protected:

	public:
	TwoLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int bottomLevelPools, int libraries);
};
