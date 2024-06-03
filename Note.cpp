#include "Note.h"
#include <iostream>
#include <set>
#include <string>
#include <Numeric>
#include <algorithm>
#include <iterator>
#include <vector>

Note::Note() = default;

const std::vector<int>& Note::getNote(std::string cell_id) const
{
	return m_notes.at(cell_id);
}

void Note::setNote(std::string cell_id, std::vector<int> updated_flag)
{
	m_notes[cell_id] = updated_flag;
}

// if there is only one remaining number in a cell
void Note::lastRemainingCell(Puzzle& puzzle)
{
	for (auto const& [key, val] : m_notes)
	{
		if (val.size() == 1)
		{
			int r = key[0] - 48;
			int c = key[2] - 48;
			puzzle.setCell(r, c, val[0]);
			m_notes[key].clear();
		}
	}
}

void Note::refreshNotes(Puzzle& puzzle)
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int cell = puzzle.getCell(i, j);
			int k = puzzle.getBoxNumber(i, j);

			std::array<int, 9> row = puzzle.getRow(i);
			std::array<int, 9> col = puzzle.getCol(j);
			std::array<int, 9> box = puzzle.getBox(k);

			std::vector unionNums = unionArray(row, col, box);
			std::vector<int> allNums = { 1,2,3,4,5,6,7,8,9 };
			std::vector<int> notes;

			std::set_difference(allNums.begin(), allNums.end(), unionNums.begin(), unionNums.end(),
				std::inserter(notes, notes.begin()));

			std::string cell_id = std::to_string(i) + '-' + std::to_string(j);

			m_notes[cell_id] = notes;
		}
	}
}



std::vector<int> Note::unionArray(std::array<int, 9> r1, std::array<int, 9> r2, std::array<int, 9> r3)
{
	std::set<int> s;
	for (int i = 0; i < 9; i++)
		s.insert(r1[i]);

	for (int i = 0; i < 9; i++)
		s.insert(r2[i]);

	for (int i = 0; i < 9; i++)
		s.insert(r3[i]);

	std::vector<int> vec(s.begin(), s.end());
	return vec;
}






