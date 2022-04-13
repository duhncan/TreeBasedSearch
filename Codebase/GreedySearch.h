#pragma once

#include "SearchMethod.h"

// GFS: Greedy Search
class GreedySearch : public SearchMethod
{
private:
	const Puzzle* m_Puzzle;
public:
	GreedySearch();

	std::vector<states> TracePath();
	void Solve(Puzzle& puzzle) override;

	inline int getIterationCount() const { return iterations; }
	inline static std::string getSMName() { return "Greedy Search"; }
	inline static std::string getSMCode() { return "gbfs"; }
};