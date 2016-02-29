#include "AverageFrag/AverageFrag.hpp"
#include "experiment/ClassicalExperiment.hpp"

int main(int argc, char* argv[]) {
	FitnessFunction * objective = new AverageFragFitness();
	ToStringFunction * objectiveTS = new AverageFragToString();
	ClassicalExperiment * experiment = new ClassicalExperiment(objective, objectiveTS, 0);

	experiment->run(false);
}
