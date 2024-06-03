#pragma once
#include "Note.h"
#include "Puzzle.h"

#include <iostream>
#include <vector>
#include <array>

class Solver
{
private:
	Puzzle m_puzzle{};
	Note m_notes{};

public:
	Solver(Puzzle puzzle);
	void solve();
	bool checkValidSolution();
	
};

