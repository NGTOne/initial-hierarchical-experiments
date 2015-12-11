#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new SSGAGeneration(strategy);

	Problem * problem = new LongFragProblem(model, 3, 4, 2, 4);
	problem->run();
}
