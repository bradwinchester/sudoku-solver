#pragma once
#include "Puzzle.h"

class Solver : public Puzzle
{
public:
	Solver(Puzzle p);

	void solve();
	void updateNotes();
	void removeNumberFromModule(int cell_id, int value);

private:
	Puzzle puzzle{};
};

