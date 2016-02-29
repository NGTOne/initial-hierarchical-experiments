#include "LongFrag/LongFrag.hpp"
#include "experiment/ClassicalExperiment.hpp"

int main(int argc, char* argv[]) {
	FitnessFunction * objective = new LongFragFitness();
	ToStringFunction * objectiveTS = new LongFragToString();
	ClassicalExperiment * experiment = new ClassicalExperiment(objective, objectiveTS, 3000);

	experiment->run(true);
}
