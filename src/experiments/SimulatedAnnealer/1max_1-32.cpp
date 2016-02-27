#include "1max/1max.hpp"
#include "experiment/ClassicalExperiment.hpp"

int main(void) {
	FitnessFunction * objective = new OneMaxFitness();
	ToStringFunction * objectiveTS = new OneMaxToString();
	ClassicalExperiment * experiment = new ClassicalExperiment(objective, objectiveTS, 3000);

	experiment->run();
}
