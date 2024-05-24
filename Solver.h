#pragma once
#include <iostream>
#include <Puzzle.h>
#include <Flag.h>
#include <vector>
#include <array>

class Solver
{
private:
	Puzzle m_puzzle{};
	Flags m_allFlags{};

public:
	Solver(Puzzle puzzle);

	
	void initializeFlags();
	void lastRemainingCell();
	std::vector<int> unionArray(std::array<int, 9> r1, std::array<int, 9> r2, std::array<int, 9> r3);
};

