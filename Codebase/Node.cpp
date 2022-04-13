#include "Node.h"
#include "SearchMethod.h"

static Node* Create(states* src, int width, int height, const Node* parent);

int Node::GetNextDirections()
{
	// Directions are stored in a single byte, with each bit defining whether a direction is available
	// Eg. 1010 == (Right: yes, left: no, down: yes, up: no), so we can move right or down
	int result = 0;
	if (position[0] > 0)
		result |= (int)Direction::LEFT;
	if (position[0] < width - 1)
		result |= (int)Direction::RIGHT;
	if (position[1] > 0)
		result |= (int)Direction::UP;
	if (position[1] < height - 1)
		result |= (int)Direction::DOWN;
	return result;
}

void GetNextStates(const states state);