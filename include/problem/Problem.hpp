#include <libHierGA/HierGA.hpp>
#include "experiment/HierExperiment.hpp"
#pragma once

class Problem {
	private:

	protected:
	HierExperiment * experiment;

	public:
	void run();
};
