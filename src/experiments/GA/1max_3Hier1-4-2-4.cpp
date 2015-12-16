#include "problem/1maxProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GAGeneration(2, strategy);

	Problem * problem = new OneMaxProblem(model, 4, 2, 4);
	problem->run();
}
