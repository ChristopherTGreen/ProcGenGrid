#pragma once

#include <vector>
#include <string>
using namespace std;


// storage for the data of a star
struct StarNode {
public: 
	enum StarRoomType {
		Empty = 0,
		Room1 = 1,
		Room2 = 2,
		Room2C = 3, // kind curious, maybe we should randomly place exits - Chris
		Room3 = 4,
		Room4 = 5,
		// Pray you don't need a 5 way - Chris note to self

	};
private:
	// Grid tile type definitions, the number following means the number of ways, C added is corner room

	StarRoomType starType = Empty;

	float XCoord;
	float YCoord;

	vector<StarNode*> neighbors;

public:

	StarNode(float, float, vector<StarNode*> neighbors = vector<StarNode*>());

	// Acts as an interface, there is no direct way to access values, or set them

	// Returns all neighbors
	vector<StarNode*> GetStarNeighbors();
	// Adds neighbor
	void AddStarNeighbor(StarNode*);
	void RemoveStarNeighbor(StarNode*);

	// Star positions
	void SetStarPosition(float, float);
	float GetStarXPosition();
	float GetStarYPosition();
	
	// Star Room Type
	void SetStarRoomType(StarRoomType);

	
};