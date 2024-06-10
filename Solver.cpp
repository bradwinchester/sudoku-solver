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
	std::vector<int> n = { 2,4 };
	puzzle.updateCell(2, n);
	/*for (auto [key, value] : puzzle) {
		if (value.size() == 1) {
			int num = value[0];
			removeNumberFromModule(key, num);
		}
	}*/
}

void Solver::removeNumberFromModule(int cell_id, int value)
{
	std::vector<int> row = getRowIds(cell_id);
	for (int i : row) {
		if (cell_id == i) { continue; } // don't remove own value from row
		std::vector cell = getCell(i);
		
		cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
		updateCell(cell_id, cell);
	}
}






