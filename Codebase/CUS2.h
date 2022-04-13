#pragma once

#include "SearchMethod.h"

// CUS2: Search
class CUS2 : public SearchMethod
{
private:
	const Puzzle* m_Puzzle;
public:
	CUS2();

	std::vector<states> TracePath();
	void Solve(Puzzle& puzzle) override;

	inline int getIterationCount() const { return iterations; }
	inline static std::string getSMName() { return "CUS2: Search"; }
	inline static std::string getSMCode() { return "cus2"; }
};