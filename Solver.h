#pragma once
#include "Puzzle.h"

class Solver : public Puzzle
{
public:
	Solver(Puzzle p);

	void solve();
	bool checkIfSolved();
	void updateNotes();
	void removeNumberFromModule(int cell_id, int value);
	void updateNakedPairs();
	void removeNakedPairs(int p1, int p2, std::vector<int> pair, std::vector<int> module);

private:
	Puzzle puzzle{};
};

