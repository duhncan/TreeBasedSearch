#include "puzzle.h"

Puzzle::Puzzle(int _width, int _height, std::vector<states> _startState, std::vector<states> _goalState, std::vector<states> _illegalStates){
	width = _width;
	height = _height;
	startState = _startState;
	goalState = _goalState;
	illegalStates = _illegalStates;
}

void Puzzle::SetCurrentState(int x, int y) {
	currentState.x = x;
	currentState.y = y;
}

void Puzzle::SetGoalState(int amount, int x, int y){

}
