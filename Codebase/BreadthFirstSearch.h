#pragma once

#include "SearchMethod.h"

// BFS: Breadth-First Search
class BreadthFirstSearch : public SearchMethod
{
private:
	const Puzzle* puzzle;
public:
	BreadthFirstSearch();

	std::vector<states> TracePath();
	void Solve(Puzzle& puzzle) override;

	inline int getIterationCount() const { return iterations; }
	inline static std::string getSMName() { return "Breadth-First Search"; }
	inline static std::string getSMCode() { return "bfs"; }
};