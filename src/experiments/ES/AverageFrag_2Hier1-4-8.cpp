#include "problem/AverageFragProblem.hpp"

int main(void) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ESGeneration(strategy);

	Problem * problem = new AverageFragProblem(model, 4, 8, false);
	problem->run();
}
