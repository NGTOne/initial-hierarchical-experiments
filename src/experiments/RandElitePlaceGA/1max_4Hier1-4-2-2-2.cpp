#include "problem/1maxProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, true, strategy);

	Problem * problem = new OneMaxProblem(model, 4, 2, 2, 2, false);
	problem->run(runSilent);
}
