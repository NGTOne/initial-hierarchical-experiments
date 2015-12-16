#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GAGeneration(0.5, strategy);

	Problem * problem = new LongFragProblem(model, 0, 16, 2);
	problem->run();
}
