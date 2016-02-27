#include "AverageFrag/AverageFrag.hpp"
#include "experiment/ClassicalExperiment.hpp"

int main(void) {
	FitnessFunction * objective = new AverageFragFitness();
	ToStringFunction * objectiveTS = new AverageFragToString();
	ClassicalExperiment * experiment = new ClassicalExperiment(objective, objectiveTS, 0);

	experiment->run();
}
