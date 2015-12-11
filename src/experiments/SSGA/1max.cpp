#include "problem/1maxProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new SSGAGeneration(strategy);

	Problem * problem = new OneMaxProblem(model, 1, 0, 0, 32);
	problem->run();
}
