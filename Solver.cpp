#include "Solver.h"
#include "Puzzle.h"

// constructor
Solver::Solver(Puzzle p) 
	: puzzle { p }
{
}

void Solver::solve()
{
	int count{};
	while (!checkIfSolved()) {
		updateNotes();
		updateNakedPairs();
		count++;
		if (count > 50) { break; }
	}
	//puzzle.printPuzzleWithNotes();
	puzzle.printPuzzle();
}

bool Solver::checkIfSolved()
{
	bool filled = true;
	for (int i = 1; i <= 81; i++) {
		auto cell = puzzle.getCell(i);
		if (cell.size() > 1) { filled = false; }
	}
	if (filled) { return true; }
	else { return false; }

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

	std::vector<int> col = puzzle.getColIds(cell_id);
	for (int i : col) {
		if (cell_id == i) { continue; } 
		std::vector cell = puzzle.getCell(i);

		cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
		puzzle.updateCell(i, cell);
	}

	std::vector<int> box = puzzle.getBoxIds(cell_id);
	for (int i : box) {
		if (cell_id == i) { continue; } 
		std::vector cell = puzzle.getCell(i);

		cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
		puzzle.updateCell(i, cell);
	}
}

void Solver::updateNakedPairs()
{
	for (int i = 1; i <= 81; i++) {
		std::vector c1 = puzzle.getCell(i);
		
		std::vector<int> row = puzzle.getRowIds(i);
		for (int j : row) {
			if (i == j) { continue; }
			
			std::vector c2 = puzzle.getCell(j);
			if ((c1 == c2) and (c1.size() == 2)) { // if they are a matching pair
				removeNakedPairs(i, j, c1, row); // remove that pair from the other cells in row
			}
		}

		std::vector<int> col = puzzle.getColIds(i);
		for (int j : col) {
			if (i == j) { continue; }

			std::vector c2 = puzzle.getCell(j);
			if ((c1 == c2) and (c1.size() == 2)) { 
				removeNakedPairs(i, j, c1, col);
			}
		}

		std::vector<int> box = puzzle.getBoxIds(i);
		for (int j : box) {
			if (i == j) { continue; }

			std::vector c2 = puzzle.getCell(j);
			if ((c1 == c2) and (c1.size() == 2)) {
				removeNakedPairs(i, j, c1, box);
			}
		}
	}
}

void Solver::removeNakedPairs(int p1, int p2, std::vector<int> pair, std::vector<int> module)
{
	for (auto i : module) {
		if (i != p1 and i != p2) {
			std::vector<int> cell = puzzle.getCell(i);
			cell.erase(remove(cell.begin(), cell.end(), pair[0]), cell.end());
			cell.erase(remove(cell.begin(), cell.end(), pair[1]), cell.end());
			puzzle.updateCell(i, cell);
		}
	}
}












