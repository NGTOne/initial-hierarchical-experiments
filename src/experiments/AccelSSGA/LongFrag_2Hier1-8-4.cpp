#include "problem/LongFragProblem.hpp"

int main(int argc, char* argv) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new AccelSSGA(strategy);

	Problem * problem = new LongFragProblem(model, 8, 4, false);
	problem->run();
}
