#include "problem/1maxProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.5);
	GenerationModel * model = new ReplacingGAGeneration(strategy);

	Problem * problem = new OneMaxProblem(model, 3, 8, 2, 2);
	problem->run();
}
