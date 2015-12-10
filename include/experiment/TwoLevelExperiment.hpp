#include "experiment/HierExperiment.hpp"
#pragma once

class TwoLevelExperiment : HierExperiment {
	private:

	protected:

	public:
	TwoLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model);
};
