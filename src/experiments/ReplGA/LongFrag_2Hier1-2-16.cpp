#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ReplacingGAGeneration(strategy);

	Problem * problem = new LongFragProblem(model, 2, 16);
	problem->run();
}
