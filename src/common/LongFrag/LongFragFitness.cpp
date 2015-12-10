#include <sstream>
#include <string>
#include <libHierGA/HierGA.hpp>
#include "LongFrag/LongFragFitness.hpp"

using namespace std;

LongFragFitness::LongFragFitness() : FitnessFunction() {}

PropertiesList * LongFragFitness::checkFitness(GenePool ** pools, int * indexes, int genomeLength) {
	int longestPathLength = 0;
	int currentPathLength = 0;
	int currentPathIndex;
	int currentDigit;
	PropertiesList * returnProperties = new PropertiesList();
	int pathLengths[genomeLength/2];
	int pathIndexes[genomeLength/2];
	int currentPath = 0;
	int currentProperty = 0;

	for (int i = 0; i < genomeLength; i++) {
		currentDigit = *(int*)pools[i]->getIndex(indexes[i]);
		currentPathIndex = i-currentPathLength;

		if (currentDigit == 1) {
			currentPathLength += 1;
		} else {
			if (currentPathLength > 0) {
	                        pathLengths[currentPath] = currentPathLength;
	                        pathIndexes[currentPath] = currentPathIndex;
        	                currentPath++;
                	        currentPathLength = 0;
			}
		}
	}

	if (currentPathLength > 0) {
		pathLengths[currentPath] = currentPathLength;
                pathIndexes[currentPath] = currentPathIndex;
                currentPath++;
                currentPathLength = 0;
        }


	for (int i = 0; i < currentPath; i++) {
		if (pathLengths[i] > longestPathLength) {
			longestPathLength = pathLengths[i];
		}
	}

	returnProperties->setFitness(longestPathLength);
	PropertyBase * newProperty = new Property<int>(&genomeLength);

	returnProperties->addProperty(newProperty);

	for (int i = 0; i < currentPath; i++) {
		newProperty = new Property<int>(&pathLengths[currentProperty]);
		returnProperties->addProperty(newProperty);
		newProperty = new Property<int>(&pathIndexes[currentProperty++]);
		returnProperties->addProperty(newProperty);
	}

	return returnProperties;
}

string LongFragToString::toString(GenePool ** pools, int * indexes, int genomeLength) {
	string returnString = "";
	stringstream ss;
	int * tempIntPtr;

	
	for (int i = 0; i < genomeLength; i++) {
		tempIntPtr = (int*)pools[i]->getIndex(indexes[i]);

		ss << *tempIntPtr;
	}

	returnString = ss.str();

	return returnString;
}
