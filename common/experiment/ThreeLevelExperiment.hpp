#include "./HierExperiment.hpp"
#pragma once

class ThreeLevelExperiment : HierExperiment {
	private:

	protected:

	public:
	ThreeLevelExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model);
};
