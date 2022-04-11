#pragma once

#include<string>
#include<vector>

#include "states.h"

class Puzzle
{
private:
	std::vector<states> goalState;
	std::vector<states> startState;
	std::vector<states> illegalStates;
	states currentState;
	int width, height;
public:
	Puzzle(int _width, int _height, std::vector<states> _startState, std::vector<states> _goalState, std::vector<states> _illegalStates);

	void SetCurrentState(int x, int y);
	void SetGoalState(int amount, int x, int y);

	void SetCurrentState(int x, int y);
	void SetGoalState(int amount, int x, int y);

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
};