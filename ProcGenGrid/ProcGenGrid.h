#pragma once

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Grid tile type definitions, the number following means the number of ways, C added is corner room
enum GridTileType {
	Empty = 0,
	Room1 = 1,
	Room2 = 2,
	Room2C = 3, // kind curious, maybe we should randomly place exits - Chris
	Room3 = 4,
	Room4 = 5,
	// Pray you don't need a 5 way - Chris note to self

};

// Grid dimensions
const int GRID_WIDTH = 50;
const int GRID_HEIGHT = 50;

// Function declarations 
string GetTileName(int tileID); // might remove
void PrintGrid(const vector<vector<int>>& grid);