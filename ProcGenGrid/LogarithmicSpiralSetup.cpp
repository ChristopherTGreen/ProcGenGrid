#include <iostream>
#include "LogarithmicSpiralSetup.h"

vector<StarNode*> LogarithmicSpiralSetup::GenerateIndexSpacedStarSpiral(int totalStars, float distance, float scaleFactor, float windingFactor) {
	vector<StarNode*> generatedStars;

	// the current angle/distance based along the spiral
	float theta = 0.1f;

	// the curve factor or physical distance based on current radius
	float curveFactor = sqrt(1.0f + (windingFactor * windingFactor));


	for (int i = 0; i < totalStars; i++) {

		// Calculate current radius using standard logarithmic formula: r = a * e^(b * theta)
		float currentRadius = scaleFactor * exp(windingFactor * theta);

		// Convert polar coordinates to Cartesian (x, y)
		float x = currentRadius * cos(theta);
		float y = currentRadius * sin(theta);

		// Retrieves the last star and converts to a new vector
		vector<StarNode*> tempStarList;
		if (!generatedStars.empty()) tempStarList = {generatedStars.back()};
		else { tempStarList; }

		// Create star
		StarNode* newStar = new StarNode(x, y, tempStarList);
		
		generatedStars.push_back(newStar);

		// Calculate the dynamic angle step (deltaTheta) for the *next* point.
		// Derived from arc length: ds = r * curveFactor * dTheta
		// Rearranged to solve for dTheta: dTheta = ds / (r * curveFactor)
		float deltaTheta = distance / (currentRadius * curveFactor);

		// Moves along the spiral 
		theta += deltaTheta;
	}
	
	return generatedStars;
}

int LogarithmicSpiralSetup::GetMaxRadiusDistance(const vector<StarNode*>& generatedStars) {
	// Finds furthest star (just checks the last star), make this its own function - chris
	StarNode* furthestStar;
	if (!generatedStars.empty()) { furthestStar = generatedStars.back(); }
	else { return 0; }

	//StarNode star = f
	
	// Calculates distance (finds radius inside) of the entire grid
	int distance = ceil(sqrt(pow(furthestStar->GetStarXPosition(), 2) + pow(furthestStar->GetStarYPosition(), 2))) * 2.0 + 1;
	return distance;
}

void LogarithmicSpiralSetup::GenerateLogarithmicGrid(const vector<StarNode*>& generatedStars) {
	int size = GetMaxRadiusDistance(generatedStars);
	vector<vector<int>> grid(size, vector<int>(size, 0));

	// Offset to deal with negatives
	int centerOffset = size / 2;
	
	for (int i = 0; i < generatedStars.size(); i++) {
		int positionX = ceil(generatedStars[i]->GetStarXPosition()) + centerOffset;
		int positionY = ceil(generatedStars[i]->GetStarYPosition()) + centerOffset;

		// Safety check
		if (positionX >= 0 && positionX < size && positionY >= 0 && positionY < size) {
			grid[positionY][positionX] = 5;
		}
	}


	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (grid[y][x] == 0) cout << " " << " ";
			else cout << grid[y][x] << " ";
		}
		cout << "\n";
	}
}