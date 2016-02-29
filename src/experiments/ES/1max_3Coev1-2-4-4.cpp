#include "problem/1maxProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ESGeneration(strategy);

	Problem * problem = new OneMaxProblem(model, 2, 4, 4, true);
	problem->run(runSilent);
}
