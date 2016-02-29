#include "problem/AverageFragProblem.hpp"

int main(int argc, char* argv[]) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new GA(2, true, strategy);

	Problem * problem = new AverageFragProblem(model, 4, 4, 2, true);
	problem->run(runSilent);
}
