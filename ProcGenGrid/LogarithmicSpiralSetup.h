#pragma once

#include <cmath>
#include <vector>
#include <tuple>
#include <string>
#include "StarNode.h"
using namespace std;

// Defines basic vector 2d
struct Vec2 {
	float x, y;
};

class LogarithmicSpiralSetup {
private:

	

	// Variables for the logarithmic spiral
	float radius; // more or less the current or output, in reference to a given point
	float scaleFactor; // initial radius or scale factor
	float eulerNumber = 2.71828f;
	float growthRate; // the winding factor, I believe how much it will curve in or out
	float angle; // angular coordinate


public:
	vector<StarNode*> GenerateIndexSpacedStarSpiral(int, float, float, float);
	int GetMaxRadiusDistance(const vector<StarNode*>&); // defaults to 0, returns the current grids max length
	void GenerateLogarithmicGrid(const vector<StarNode*>&);
	// Returns the point in the spiral which is equally distanced based on the given distance limit
	
};




