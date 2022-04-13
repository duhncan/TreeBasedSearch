#pragma once

#include <vector>
#include <string>
#include "puzzle.h"
#include "states.h"
#include "Node.h"


using namespace std;

class SearchMethod {
protected:
	vector<vector<int>> coordPath;
	vector<Direction> directionalPath;
	vector<Node> visitedNodes;
	int iterations;
	bool solved;

public:
	
	SearchMethod() : iterations(0), solved(false) {}
	virtual ~SearchMethod() {}

	// Solves the puzzle given within the parameter
	virtual void Solve(Puzzle& puzzle) {}

	// Returns whether the puzzle is solved
	inline bool isSolved() { return solved;	}

	// Returns true or false to given state
	bool isVisited(int x, int y){
		for (int i = 0; i < visitedNodes.size(); i++) {
			if (x == visitedNodes[i].position[0]) {
				if (y == visitedNodes[i].position[1]) {
					return true;
				}
			}
		}
		return false;
	}

	// Adds a new state to path
	void addToPath(vector<int>) {}

	// Clears the solution path
	inline void clearSolutionPath() { coordPath.clear(); directionalPath.clear(); }

	// Gets 
	inline vector<vector<int>> getPath() { return coordPath; }

	inline vector<Direction> getDirectionalPath() { return directionalPath; }

	inline int getIterations() { return iterations; }

	inline int getSteps() { return coordPath.size(); }





};