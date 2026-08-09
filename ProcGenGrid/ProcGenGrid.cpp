// ProcGenGrid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ProcGenGrid.h"
using namespace std;

string GetTileName(int tileID)
{
    switch (tileID) 
    {
        case 0: return "Empty";
        case 1: return "Room1";
        case 2: return "Room2";
        case 3: return "Room2C";
        case 4: return "Room3";
        case 5: return "Room4";
    }
}

void PrintGrid(const vector<vector<int>>& grid) 
{
    for (int y = 0; y < GRID_HEIGHT; y++) 
    {
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            cout << grid[y][x] << " ";
        }
        cout << "\n\n";
    }
}





int main()
{
    vector<vector<int>> grid(GRID_HEIGHT, vector<int>(GRID_WIDTH, 0));

    // procedural logic here

    PrintGrid(grid);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
