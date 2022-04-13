#pragma once

#include "SearchMethod.h"

// AFS: A Star Search
class AStarSearch : public SearchMethod
{
private:
	const Puzzle* m_Puzzle;
public:
	AStarSearch();

	std::vector<states> TracePath();
	void Solve(Puzzle& puzzle) override;

	inline int getIterationCount() const { return iterations; }
	inline static std::string getSMName() { return "A Star Search"; }
	inline static std::string getSMCode() { return "afs"; }
};