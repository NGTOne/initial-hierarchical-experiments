CPPC = g++
CPPFLAGS = -c -g -std=gnu++0x -fPIC
INCLUDE = -Iinclude

SHAREDLIB = -lHierGA

info:
	@echo "Usage:"
	@echo "make library: Rebuilds the library from scratch"
	@echo "make install: Installs the compiled library and header files into /usr"
	@echo "make examples: Produces a series of examples GAs and hierarchical GAs using the shared library. Requires make install to be run first."
	@echo "make uninstall: Uninstalls the library and header files"
	@echo "make clean: Cleans up all compiled binaries and object files"
	@echo "make core: Produces the object files for the \"core\" components"
	@echo "make selections: Produces the object files for the selection strategies"
	@echo "make mutations: Produces the object files for the mutation operators"
	@echo "make crossovers: Produces the object files for the crossover operators"
	@echo ""
	@echo "Any GA/HGA needs at least core, and one component from each of selections, mutations, and crossovers in order to function."

common: experiment

experiment:
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/HierExperiment.cpp -o obj/HierExperiment.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/ClassicalExperiment.cpp -o obj/ClassicalExperiment.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/TwoLevelExperiment.cpp -o obj/TwoLevelExperiment.o
	$(CPPC) $(CPPFLAGS) $(INCLUDE) src/common/experiment/ThreeLevelExperiment.cpp -o obj/ThreeLevelExperiment.o

clean:
	find obj -name *.o | xargs rm -f
