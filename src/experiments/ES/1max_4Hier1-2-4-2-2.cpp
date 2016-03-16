#include "problem/1maxProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ES(0.5, 0.5, strategy);

	Problem * problem = new OneMaxProblem(model, 2, 4, 2, 2, false);
	problem->run(runSilent);
}
