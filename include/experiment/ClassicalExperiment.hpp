#include "experiment/HierExperiment.hpp"
#pragma once

class ClassicalExperiment : public HierExperiment {
	private:

	protected:
	Individual * getTemplateIndividual(FitnessFunction * objective, ToStringFunction * objectiveTS);

	public:
	ClassicalExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, FitnessFunction * promise, ToStringFunction * promiseTS, GenerationModel * model);

	// For setting up experiments with annealers
	ClassicalExperiment(FitnessFunction * objective, ToStringFunction * objectiveTS, int initialTemp);
};
