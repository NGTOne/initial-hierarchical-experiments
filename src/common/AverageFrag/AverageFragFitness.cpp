#include <sstream>
#include <string>
#include <iostream>
#include <libHierGA/HierGA.hpp>
#include "AverageFrag/AverageFragFitness.hpp"

using namespace std;

AverageFragFitness::AverageFragFitness() : FitnessFunction() {}

PropertiesList * AverageFragFitness::checkFitness(GenePool ** pools, int * indexes, int genomeLength) {
	int currentPathLength = 0;
	int currentPathIndex;
	int currentDigit;
	PropertiesList * returnProperties = new PropertiesList();
	int pathLengths[genomeLength/2];
	int pathIndexes[genomeLength/2];
	int currentPath = 0;
	int currentProperty = 0;
	int numPaths = 0;
	int overallPathLength = 0;
	float averageLength;
	int returnFitness;

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
		overallPathLength += pathLengths[i];
	}

	averageLength = (float)overallPathLength/(float)currentPath;
	returnFitness = floor(averageLength);

	returnProperties->setFitness(returnFitness);
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

string AverageFragToString::toString(GenePool ** pools, int * indexes, int genomeLength) {
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
