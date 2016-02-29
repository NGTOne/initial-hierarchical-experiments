#include "1max/1max.hpp"
#include "experiment/ClassicalExperiment.hpp"

int main(int argc, char* argv[]) {
	FitnessFunction * objective = new OneMaxFitness();
	ToStringFunction * objectiveTS = new OneMaxToString();
	ClassicalExperiment * experiment = new ClassicalExperiment(objective, objectiveTS, 0);

	experiment->run(false);
}
