#include "problem/1maxProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, false, strategy);

	Problem * problem = new OneMaxProblem(model, 8, 4, false);
	problem->run(runSilent);
}
