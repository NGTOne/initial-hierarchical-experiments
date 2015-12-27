#include "experiment/HierExperiment.hpp"
#pragma once

class FiveLevelExperiment : public HierExperiment {
	private:

	protected:

	public:
	FiveLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model, int secondLevelPools, int thirdLevelPools, int fourthLevelPools, int bottomLevelPools, int libraries, bool coevolutionary);
};
