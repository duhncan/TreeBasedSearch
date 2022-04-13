#include "puzzle.h"

#include <iomanip> // To draw Puzzle
#include <iostream> // DELETE THIS

Puzzle::Puzzle(int _height, int _width){
	Puzzle::width = _width;
	Puzzle::height = _height;
}

void Puzzle::SetStartState(int x, int y) {
	Puzzle::startState.x = x;
	Puzzle::startState.y = y;
}

void Puzzle::AddGoalState(int x, int y) {
	//std::cout << "Goal State Added @ x: " << x << " y: " << y << std::endl;
	states temp;
	temp.x = x;
	temp.y = y;
	Puzzle::goalState.push_back(temp);
}


void Puzzle::AddIllegalState(int x, int y) {
	//std::cout << "Illegal State Added @ x: " << x << " y: " << y << std::endl;
	states temp;
	temp.x = x;
	temp.y = y;
	Puzzle::illegalStates.push_back(temp);
}

void Puzzle::DrawPuzzle() {

	//std::cout << "Puzzle Size" << std::endl;
	//std::cout << width << " , " << height << std::endl;

	//std::cout << "Start State" << std::endl;
	//std::cout << startState.x << " , " << startState.y << std::endl;

	//std::cout << "Illegal States" << std::endl;
	//for (auto j : illegalStates) {
	//	std::cout << "\t[\t" << j.x << "\t" << j.y << "\t" << j.height << "\t" << j.width << "\t]" << std::endl;
	//}

	//std::cout << "Goal States" << std::endl;
	//for (auto j : goalState) {
	//	std::cout << "\t[\t" << j.x << "\t" << j.y << "\t" << j.height << "\t" << j.width << "\t]" << std::endl;
	//}

	
	for (int i = 0; i < Puzzle::GetHeight(); i++) {
		for (int j = 0; j < Puzzle::GetWidth(); j++) {
			if (j == Puzzle::GetWidth() || j == 0) std::cout << "\n | ";
			std::cout << std::setw(3) << GetStateStatus(j,i) << " | ";
		}
	}
	std::cout << "\n" << std::endl;
}

int Puzzle::GetStateStatus(int x, int y) {

	// Check Illegal State = 1
	for (auto i : illegalStates) {
		if (x == i.x && y == i.y) return 1;
	}
	// Check Goal State = 2
	for (auto i : goalState) {
		if (x == i.x && y == i.y) return 2;
	}
	// Check Start State = 3
	if (x == startState.x && y == startState.y) return 3;

	return 0;
}

// Finding Open Tile of a State based on order of UP, LEFT, DOWN, RIGHT
std::vector<states> Puzzle::FindOpenTile(int x, int y)
{
	std::vector<states> openTiles;
	states openTile;

	// Check UP
	openTile.x = x;
	openTile.y = y;
	openTile.y--;
	if ( (openTile.x < this->GetWidth() && openTile.x >= 0) && (openTile.y < this->GetHeight() && openTile.y >= 0)) {
		if (Puzzle::GetStateStatus(openTile.x, openTile.y)==0) {
			openTiles.push_back(openTile);
		}
		else {
			openTile.x = -1;
			openTile.y = -1;
			openTiles.push_back(openTile);
		}
	}
	else {
		openTile.x = x;
		openTile.y = y;
		openTiles.push_back(openTile);
	}

	// Check LEFT
	openTile.x = x;
	openTile.y = y;
	openTile.x--;
	if ((openTile.x < this->GetWidth() && openTile.x >= 0) && (openTile.y < this->GetHeight() && openTile.y >= 0)) {
		if (Puzzle::GetStateStatus(openTile.x, openTile.y) == 0) {
			openTiles.push_back(openTile);
		}
		else {
			openTile.x = -1;
			openTile.y = -1;
			openTiles.push_back(openTile);
		}
	}
	else {
		openTile.x = -1;
		openTile.y = -1;
		openTiles.push_back(openTile);
	}

	// Check DOWN
	openTile.x = x;
	openTile.y = y;
	openTile.y++;
	if ((openTile.x < this->GetWidth() && openTile.x >= 0) && (openTile.y < this->GetHeight() && openTile.y >= 0)) {
		if (Puzzle::GetStateStatus(openTile.x, openTile.y) == 0) {
			openTiles.push_back(openTile);
		}
		else {
			openTile.x = -1;
			openTile.y = -1;
			openTiles.push_back(openTile);
		}
	}
	else {
		openTile.x = -1;
		openTile.y = -1;
		openTiles.push_back(openTile);
	}

	// Check RIGHT
	openTile.x = x;
	openTile.y = y;
	openTile.x++;
	if ((openTile.x < this->GetWidth() && openTile.x >= 0) && (openTile.y < this->GetHeight() && openTile.y >= 0)) {
		if (Puzzle::GetStateStatus(openTile.x, openTile.y) == 0) {
			openTiles.push_back(openTile);
		}
		else {
			openTile.x = -1;
			openTile.y = -1;
			openTiles.push_back(openTile);
		}
	}
	else {
		openTile.x = -1;
		openTile.y = -1;
		openTiles.push_back(openTile);
	}

	return openTiles;

}




