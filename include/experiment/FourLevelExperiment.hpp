#include "experiment/HierExperiment.hpp"
#pragma once

class FourLevelExperiment : public HierExperiment {
	private:

	protected:

	public:
	FourLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int secondLevelPools, int thirdLevelPools, int bottomLevelPools, int libraries);
};
