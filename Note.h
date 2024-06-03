#pragma once
#include "Puzzle.h"
#include <array>
#include <vector>
#include <map>
#include <string>

class Note : public Puzzle
{
private:
	std::map<std::string, std::vector<int>> m_notes;

public:
	Note();
	const std::vector<int>& getNote(std::string cell_id) const;
	void setNote(std::string cell_id, std::vector<int> updated_note);

	void lastRemainingCell(Puzzle& puzzle);
	void refreshNotes(Puzzle& puzzle);
	
	// returns the union of three std::arrays (rows, cols, and box) as a vector
	std::vector<int> unionArray(std::array<int, 9> r1, std::array<int, 9> r2, std::array<int, 9> r3);

};

