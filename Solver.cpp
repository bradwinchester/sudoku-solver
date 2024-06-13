#include "Solver.h"
#include "Puzzle.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

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
		updateNakedTriples("row");
		updateNakedTriples("col");
		updateNakedTriples("box");
		updateHiddenPairs();
		
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

// searches for matching triplets, and removes those possibilites from the other cells in it's module
void Solver::updateNakedTriples(std::string mod_type)
{
	for (int i = 1; i <= 81; i++) {
		std::vector c1 = puzzle.getCell(i);
		if (c1.size() > 3 or c1.size() == 1) { continue; } // skip if there are more than three possibilities or the cell is solved
		
		std::vector<int> module{};
		if (mod_type == "row") { module = puzzle.getRowIds(i); }
		if (mod_type == "col") { module = puzzle.getColIds(i); }
		if (mod_type == "box") { module = puzzle.getBoxIds(i); }
		
		for (int j : module) {
			if (i == j) { continue; }

			std::set<int> triplet{};
			for (auto x : c1) { triplet.insert(x); } // add all elements of first cell to a set

			std::vector c2 = puzzle.getCell(j);
			if (c2.size() > 3 or c2.size() == 1) { continue; }
			
			for (auto x : c2) { triplet.insert(x); }
			if (triplet.size() > 3) { continue; } // not triplets, break

			for (int k : module) {
				if (i == k or j == k) { continue; }
				std::vector c3 = puzzle.getCell(k);
				if (c3.size() > 3 or c3.size() == 1) { continue; }

				for (auto x : c3) { triplet.insert(x); }
				if (triplet.size() > 3) { continue; } // not triplets, break
				
				if (triplet.size() == 3) { removeNakedTriplets(i, j, k, triplet, module); }
			}
		}
	}
}

void Solver::removeNakedTriplets(int i, int j, int k, std::set<int> triplet, std::vector<int> module)
{
	for (auto x : module) {
		if ((x != i) and (x != j) and (x != k)) {
			std::vector<int> cell = puzzle.getCell(x);
			if (cell.size() == 1) { continue; }
			for (auto y : triplet) {
				cell.erase(remove(cell.begin(), cell.end(), y), cell.end());
			}
			puzzle.updateCell(x, cell);
		}
	}
}

// iterates through every row, column, and box (module) to find hidden pairs 
void Solver::updateHiddenPairs()
{
	for (int i = 1; i <= 73; i += 9) { isolateHiddenPairs(i, "row"); }
	for (int i = 1; i <= 9 ; i++) { isolateHiddenPairs(i, "col"); }
	
	std::vector<int> box_ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 };
	for (auto i : box_ids) {
		isolateHiddenPairs(i, "box");
	}
}

// removes all other possibilites from cells containing hidden pairs 
void Solver::isolateHiddenPairs(int index, std::string mod_type)
{
	std::vector<int> module{};
	if (mod_type == "row") { module = puzzle.getRowIds(index); }
	if (mod_type == "col") { module = puzzle.getColIds(index); }
	if (mod_type == "box") { module = puzzle.getBoxIds(index); }

	std::map<int, std::vector<int>> found_idx{};
	for (int j = 1; j <= 9; j++) { // each possible number in a cell
		for (int k : module) { // each cell in module
			std::vector<int> cell = puzzle.getCell(k);
			if (cell.size() > 1) {
				if (std::find(cell.begin(), cell.end(), j) != cell.end()) {
					found_idx[j].push_back(k);
				}
			}
		}
	}
	std::map<int, std::vector<int>> pairs{};
	for (auto const& [key, val] : found_idx) {
		for (int key2 = 1; key2 <= 9; key2++) {
			if (key == key2) { continue; }
			std::vector<int> val2 = found_idx[key2];
			if (val == val2 and val.size() == 2) {
				puzzle.updateCell(val[0], { key, key2 });
				puzzle.updateCell(val[1], { key, key2 });
			}
		}
	}
}
















