#include "problem/1maxProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new SSGAGeneration(strategy);

	Problem * problem = new OneMaxProblem(model, 2, 0, 16, 2);
	problem->run();
}