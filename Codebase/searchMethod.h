#pragma once

#include <vector>
#include "states.h"
#include "puzzle.h"

using namespace std;

class SearchMethod {
private:
	vector<vector<int>> path;
	int iterations;
	bool solved;

public:
	
	SearchMethod(){}
	virtual ~SearchMethod() {}

	// Solves the puzzle given within the parameter
	virtual void Solve(const Puzzle& puzzle) {}

	// Returns whether the puzzle is solved
	inline bool isSolved() { return solved;	}

	// Returns true or false to given state
	bool isVisited(vector<int>){}

	// Adds a new state to path
	void addToPath(vector<int>) {}

	// Clears the solution path
	inline void clearSolutionPath() { path.clear(); }
	

};