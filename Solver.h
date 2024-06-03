#pragma once
#include <iostream>
#include <Puzzle.h>
#include <Note.h>
#include <vector>
#include <array>

class Solver
{
private:
	Puzzle m_puzzle{};
	Note m_notes{};

public:
	Solver(Puzzle puzzle);

	void solveNext();
	void initializeFlags();
	void lastRemainingCell();

	// returns the union of three std::arrays (rows, cols, and box) as a vector
	std::vector<int> unionArray(std::array<int, 9> r1, std::array<int, 9> r2, std::array<int, 9> r3);
};

