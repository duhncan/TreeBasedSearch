#pragma once

#include "SearchMethod.h"

// DFS: Depth-First Search
class DepthFirstSearch : public SearchMethod
{
private:
	const Puzzle* m_Puzzle;
public:
	DepthFirstSearch();

	std::vector<states> TracePath();
	void Solve(Puzzle& puzzle) override;

	inline int getIterationCount() const { return iterations; }
	inline static std::string getSMName() { return "Depth-First Search"; }
	inline static std::string getSMCode() { return "dfs"; }
};