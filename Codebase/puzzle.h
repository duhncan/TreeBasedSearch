#pragma once

#include<string>
#include<vector>


#include "states.h"

class Puzzle
{
private:
	states startState;
	std::vector<states> goalState;
	std::vector<states> illegalStates;
	int width, height;
public:
	Puzzle(int _width, int _height);

	void SetStartState(int x, int y);
	void AddGoalState(int x, int y);
	void AddIllegalState(int x, int y);

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
	inline states GetStartState() const { return startState; }
	int GetStateStatus(int x, int y);

	inline void ClearGoalStates() { goalState.clear(); }
	inline void ClearCurrentState() { startState.x = startState.y = NULL; }	
	inline void ClearIllegalStates() { illegalStates.clear(); }

	std::vector<states> FindOpenTile(int x, int y);

	void DrawPuzzle();

};