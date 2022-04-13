#include "BreadthFirstSearch.h"
#include <queue>

#include <iostream>


BreadthFirstSearch::BreadthFirstSearch() {}

void BreadthFirstSearch::Solve(Puzzle& _puzzle) {

	
	//BreadthFirstSearch::clearSolutionPath();


	BreadthFirstSearch::visitedNodes.clear();

	//Create First Node and List
	Node* root = Node::Create(&_puzzle.GetStartState(), _puzzle.GetWidth(), _puzzle.GetHeight(), nullptr);
	std::vector<Node> nodes;
	nodes.push_back(*root);

	// Find free states
	vector<states> free = _puzzle.FindOpenTile(_puzzle.GetStartState().x,_puzzle.GetStartState().y);
	std::queue<Node*> searchNodes;
	searchNodes.push(root);



	//
	//for (auto i : free) {
	//	std::cout << "\t[\t" << i.x << "\t" << i.y << "\t" << i.height << "\t" << i.width << "\t]" << std::endl;
	//}



	








	solved = true;
	
}