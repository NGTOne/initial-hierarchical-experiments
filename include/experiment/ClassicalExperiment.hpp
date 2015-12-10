#include "experiment/HierExperiment.hpp"
#pragma once

class ClassicalExperiment : HierExperiment {
	private:

	protected:

	public:
	ClassicalExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model);
};
