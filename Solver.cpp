#include "Solver.h"
#include "Puzzle.h"
#include <iostream>
#include <algorithm>

// constructor
Solver::Solver(Puzzle p) 
	: puzzle { p }
{
}

// iteratively attempts to solve the puzzle using the algorithms
// stops after 100 iterations
void Solver::solve()
{
	int count{};
	while (!checkIfSolved()) {
		updateNotes();
		updateNakedPairs();
		count++;
		if (count > 100) { break; } // prevents infinite loop
	}
	puzzle.printPuzzleWithNotes();
}

// checks if the puzzle is solved with a valid solution
bool Solver::checkIfSolved()
{
	for (int i = 1; i <= 9; i++) { 
		std::vector<int> row{};
		std::map<int, std::vector<int>> r = puzzle.getRow(i);

		for (auto const& [key, val] : r) {
			row.insert(row.end(), val.begin(), val.end());
		}
		
		if (row.size() > 9) { return false; } 

		std::sort(row.begin(), row.end());
		std::vector<int> nums = { 1,2,3,4,5,6,7,8,9 };

		if (row != nums) {
			std::cout << "Invalid Solution!";
			return false;
		}
	}

	for (int i = 1; i <= 9; i++) {
		std::vector<int> col{};
		std::map<int, std::vector<int>> c = puzzle.getCol(i);

		for (auto const& [key, val] : c) {
			col.insert(col.end(), val.begin(), val.end());
		}

		if (col .size() > 9) { return false; }

		std::sort(col.begin(), col.end());
		std::vector<int> nums = { 1,2,3,4,5,6,7,8,9 };

		if (col != nums) {
			std::cout << "Invalid Solution!";
			return false;
		}
	}

	for (int i = 1; i <= 9; i++) {
		std::vector<int> box{};
		std::map<int, std::vector<int>> b = puzzle.getBox(i);

		for (auto const& [key, val] : b) {
			box.insert(box.end(), val.begin(), val.end());
		}

		if (box.size() > 9) { return false; }

		std::sort(box.begin(), box.end());
		std::vector<int> nums = { 1,2,3,4,5,6,7,8,9 };

		if (box != nums) {
			std::cout << "Invalid Solution!";
			return false;
		}
	}
	return true;
}

// removes the already solved cells as a possibility from the relevant modules
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

// removes a solved cell from each module it is a part of 
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

// searches for matching pairs, and removes those possibilites from the other cells in it's module
void Solver::updateNakedPairs()
{
	for (int i = 1; i <= 81; i++) {
		std::vector c1 = puzzle.getCell(i);
		
		std::vector<int> row = puzzle.getRowIds(i);
		for (int j : row) {
			if (i == j) { continue; }
			
			std::vector c2 = puzzle.getCell(j);
			if ((c1 == c2) and (c1.size() == 2)) { // if they are a matching pair
				removeNakedPair(i, j, c1, row); // remove that pair from the other cells in row
			}
		}

		std::vector<int> col = puzzle.getColIds(i);
		for (int j : col) {
			if (i == j) { continue; }

			std::vector c2 = puzzle.getCell(j);
			if ((c1 == c2) and (c1.size() == 2)) { 
				removeNakedPair(i, j, c1, col);
			}
		}

		std::vector<int> box = puzzle.getBoxIds(i);
		for (int j : box) {
			if (i == j) { continue; }

			std::vector c2 = puzzle.getCell(j);
			if ((c1 == c2) and (c1.size() == 2)) {
				removeNakedPair(i, j, c1, box);
			}
		}
	}
}

// removes the numbers in a matching pair from every cell in the module, except the cells the pair is 
void Solver::removeNakedPair(int p1, int p2, std::vector<int> pair, std::vector<int> module)
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
















