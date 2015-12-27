#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GAGeneration(2, strategy);

	Problem * problem = new LongFragProblem(model, 4, 4, 2, false);
	problem->run();
}
