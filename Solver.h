#pragma once
#include "Puzzle.h"
#include <set>
#include <string>

class Solver : public Puzzle
{
public:
	Solver(Puzzle p);

	void solve();
	bool isSolved();
	void updateNotes();
	void removeNumberFromModule(int cell_id, int value);
	
	void updateNakedPairs();
	void findNakedPairs(int index, std::string mod_type);
	void removeNakedPair(int p1, int p2, std::vector<int> pair, std::vector<int> module);
	
	void updateNakedTriples();
	void removeNakedTriples(int index, std::string mod_type);

	void updateHiddenPairs();
	void isolateHiddenPairs(int index, std::string mod_type);
	
	void updateHiddenTriples();
	void isolateHiddenTriples(int index, std::string mod_type);



private:
	Puzzle puzzle{};
};

