#pragma once

#include "SearchMethod.h"

// CUS1: Search
class CUS1 : public SearchMethod
{
private:
	const Puzzle* m_Puzzle;
public:
	CUS1();

	std::vector<states> TracePath();
	void Solve(Puzzle& puzzle) override;

	inline int getIterationCount() const { return iterations; }
	inline static std::string getSMName() { return "CUS1: Search"; }
	inline static std::string getSMCode() { return "cus1"; }
};