#include "experiment/HierExperiment.hpp"
#pragma once

class ThreeLevelExperiment : public HierExperiment {
	private:

	protected:

	public:
	ThreeLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int midLevelPools, int bottomLevelPools, int libraries);
};
