#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new GAGeneration(0.5, strategy);

	Problem * problem = new LongFragProblem(model, 2, 0, 4, 8);
	problem->run();
}
