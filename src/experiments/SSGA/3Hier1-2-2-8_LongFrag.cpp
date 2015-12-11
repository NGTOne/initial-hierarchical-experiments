#include "problem/LongFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new SSGAGeneration(strategy);

	Problem * problem = new LongFragProblem(model, 3, 2, 8, 2);
	problem->run();
}
