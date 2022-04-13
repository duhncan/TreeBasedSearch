#pragma once

struct states {
	int x, y, width, height;;
};

enum class Direction : int
{
	NONE = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4,
};

static std::string DirectionToString(Direction direction)
{
	switch (direction)
	{
	case Direction::NONE:	return "None";
	case Direction::UP:		return "Up";
	case Direction::DOWN:	return "Down";
	case Direction::LEFT:	return "Left";
	case Direction::RIGHT:	return "Right";
	}
	return "Unknown";
}