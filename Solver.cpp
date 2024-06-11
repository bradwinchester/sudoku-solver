#include "Solver.h"
#include "Puzzle.h"

// constructor
Solver::Solver(Puzzle p) 
	: puzzle { p }
{
}

void Solver::solve()
{
	updateNotes();
	puzzle.printPuzzleWithNotes();
}

void Solver::updateNotes()
{
	for (int i = 1; i <= 81; i++) {
		auto cell = puzzle.getCell(i);
		if (cell.size() == 1) {
			int num = cell[0];
			removeNumberFromModule(i, num);
		}
	}
}

void Solver::removeNumberFromModule(int cell_id, int value)
{
	std::vector<int> row = puzzle.getRowIds(cell_id);
	for (int i : row) {
		if (cell_id == i) { continue; } // don't remove own value from row
		std::vector cell = puzzle.getCell(i);
		
		cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
		puzzle.updateCell(i, cell);
	}
}






