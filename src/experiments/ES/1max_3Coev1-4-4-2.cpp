#include "problem/1maxProblem.hpp"

int main(int argc, char* argv) {
	SelectionStrategy * strategy = new TournamentSelection(0.9);
	GenerationModel * model = new ESGeneration(strategy);

	Problem * problem = new OneMaxProblem(model, 4, 4, 2, true);
	problem->run();
}
