#include <iostream>
#include "StarNode.h"
using namespace std;

StarNode::StarNode(float givenX, float givenY, vector<StarNode*> starNeighbors) {
	XCoord = givenX;
	YCoord = givenY;
	neighbors.assign(starNeighbors.begin(), starNeighbors.end());
}


vector<StarNode*> StarNode::GetStarNeighbors() {
	return neighbors;
}

void StarNode::AddStarNeighbor(StarNode* neighborStar) {
	neighbors.push_back(neighborStar);
}

void StarNode::RemoveStarNeighbor(StarNode* neighborStar) {
	// finds the element (probably better way to do this) - chris
	auto it = find(neighbors.begin(), neighbors.end(), neighborStar);

	// Check if element exists
	if (it != neighbors.end()) {
		neighbors.erase(it); // Erase the element
	}
}

void StarNode::SetStarPosition(float givenX, float givenY) {
	XCoord = givenX;
	YCoord = givenY;
}

float StarNode::GetStarXPosition() {
	return XCoord;
}
float StarNode::GetStarYPosition() {
	return YCoord;
}

void StarNode::SetStarRoomType(StarRoomType newStarRoomType) {
	starType = newStarRoomType;
}