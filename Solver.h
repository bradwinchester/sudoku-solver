#pragma once
#include "Puzzle.h"
#include <set>

class Solver : public Puzzle
{
public:
	Solver(Puzzle p);

	void solve();
	bool checkIfSolved();
	void updateNotes();
	void removeNumberFromModule(int cell_id, int value);
	void updateNakedPairs();
	void removeNakedPair(int p1, int p2, std::vector<int> pair, std::vector<int> module);
	void updateNakedTriples();
	void removeNakedTriplets(int i, int j, int k, std::set<int> s, std::vector<int> module);

private:
	Puzzle puzzle{};
};

