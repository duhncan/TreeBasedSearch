#pragma once
#include <vector>
#include "states.h"

struct Node
{
	int width, height;
	const Node* parent; // Pointer to this node's parent
	std::vector<int> position; // Position of blank tile in the puzzle
	Direction direction; // Move direction which led to this node

	// Costs for informed
	short fCost, gCost, hCost;

	static Node* Create(states* src, int width, int height, const Node* parent);

	~Node();
	int GetNextDirections();
	void GetNextStates(const states state);

	//void SetCost(short gCost, short hCost);

	//inline bool operator==(const Node& other) const { return GetState() == other.GetState(); }

	//inline bool operator!=(const Node& other){ return !(*this == other); }

	//states& GetState() const
	//{
	//	// This function return a reference to this Node's State. Since we store
	//	// it at the end of our Node struct, we can just return a dereferenced
	//	// pointer offset to the next byte after our Node struct, since that
	//	// will be the beginning of the State data
	//	return *(states*)(this + 1);
	//}
private:
	// Private constructor since we need to allocate enough space for State (via Node::Create)
	Node(states* state, int width, int height, const Node* parent);
};