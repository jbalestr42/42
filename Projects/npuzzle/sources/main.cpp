#include "AStar.hpp"
#include <iostream>
#include <queue>
#include <memory>
#include <map>

int main(void)
{
	//Puzzle::PuzzleState g = { 1, 2, 3, 8, 0, 4, 7, 6, 5 };
	//Puzzle start(3);
	//Puzzle goal(g, 3);

	AStar aStar;
	AStar::PuzzleState start = { { 5, 2, 0, 4, 7, 6, 8, 3, 1 }, 0, 0 };
	//AStar::PuzzleState start = { { 2, 3, 4, 1, 8, 0, 7, 6, 5 }, 0, 0 };
	AStar::PuzzleState goal = { { 1, 2, 3, 8, 0, 4, 7, 6, 5 }, 0, 0 };
	aStar.solve(start, goal);

	return (0);
}
