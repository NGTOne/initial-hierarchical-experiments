#include "LongFrag/LongFrag.hpp"
#include "experiment/ClassicalExperiment.hpp"

int main(void) {
	FitnessFunction * objective = new LongFragFitness();
	ToStringFunction * objectiveTS = new LongFragToString();
	ClassicalExperiment * experiment = new ClassicalExperiment(objective, objectiveTS, 0);

	experiment->run();
}
