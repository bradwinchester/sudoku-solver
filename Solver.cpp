#include <iostream>
#include <algorithm>
#include "Solver.h"
#include "Note.h"
#include <Numeric>
#include <vector>
#include <array>
#include <set>
#include <string>

Solver::Solver(Puzzle puzzle)
	: m_puzzle { puzzle } 
{
	initializeFlags();
	
}

void Solver::solveNext()
{
}

void Solver::initializeFlags()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) { 
			int cell = m_puzzle.getCell(i, j);
			int k = m_puzzle.getBoxNumber(i, j);

			auto row = m_puzzle.getRow(i);
			auto col = m_puzzle.getCol(j);
			auto box = m_puzzle.getBox(k);
			
			std::vector unionNums = unionArray(row, col, box);
			std::vector<int> allNums = { 1,2,3,4,5,6,7,8,9 };
			std::vector<int> notes;

			std::set_difference(allNums.begin(), allNums.end(), unionNums.begin(), unionNums.end(),
				std::inserter(notes, notes.begin()));

			std::string cell_id = std::to_string(i) + '-' + std::to_string(j);
			m_notes.setNote(cell_id, notes);

		}
	}
}

void Solver::lastRemainingCell()
{
	for (int i = 1; i < 10; i++) 
	{
		auto box = m_puzzle.getBox(i);
		int box_total = std::accumulate(box.begin(), box.end(), 0);
	}
}

std::vector<int> Solver::unionArray(std::array<int, 9> r1, std::array<int, 9> r2, std::array<int, 9> r3)
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




