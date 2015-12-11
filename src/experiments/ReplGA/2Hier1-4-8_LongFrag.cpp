#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new ReplacingGAGeneration(strategy);

	Problem * problem = new LongFragProblem(model, 2, 0, 4, 8);
	problem->run();
}
