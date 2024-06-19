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
	while (!isSolved()) {
		updateNotes();
		
		updateNakedPairs();
		updateNakedTriples();

		updateHiddenPairs();
		updateHiddenTriples();

		count++;
		if (count > 10) { break; } // prevents infinite loop
	}
	puzzle.printPuzzleWithNotes();
}

// checks if the puzzle is solved with a valid solution
bool Solver::isSolved()
{
	std::vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
	
	bool row_solved = false;
	std::vector<int> row;
	for (int i = 1; i <= 73; i += 9) {
		std::vector<int> row_ids = puzzle.getRowIds(i);

		for (int j : row_ids) {
			std::vector<int> cell = puzzle.getCell(j);
			if (cell.empty()) {
				std::cout << "Error! Cell " << j << "is blank!" << '\n';
				return false;
			}
			
			row.push_back(cell[0]);
		}
	}
	std::sort(row.begin(), row.end());
	if (row == nums) { row_solved = true; }

	bool col_solved = false;
	std::vector<int> col;
	for (int i = 1; i <= 9; i++) {
		std::vector<int> col_ids = puzzle.getColIds(i);

		for (int j : col_ids) {
			std::vector<int> cell = puzzle.getCell(j);
			if (cell.empty()) {
				std::cout << "Error! Cell " << j << "is blank!" << '\n';
				return false;
			}
			
			col.push_back(cell[0]);
		}
	}
	std::sort(col.begin(), col.end());
	if (col == nums) { col_solved = true; }

	bool box_solved = false;
	std::vector<int> box;
	std::vector<int> ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 };
	for (auto i : ids) {
		std::vector<int> box_ids = puzzle.getBoxIds(i);

		for (int j : box_ids) {
			std::vector<int> cell = puzzle.getCell(j);
			if (cell.empty()) {
				std::cout << "Error! Cell " << j << "is blank!" << '\n';
				return false;
			}
			
			box.push_back(cell[0]);
		}
	}
	std::sort(box.begin(), box.end());
	if (box == nums) { box_solved = true; }
	
	if (row_solved and col_solved and box_solved) {
		std::cout << "Puzzle Solved!" << '\n';
		return true;
	}
	else {
		return false;
	}
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
		if (cell.size() == 1) { continue; }

		if (std::find(cell.begin(), cell.end(), value) != cell.end()) {
			cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
			puzzle.updateCell(i, cell);
			std::cout << "updated notes: " << value << " removed from cell " << i << " : row" << '\n';
		}
	}

	std::vector<int> col = puzzle.getColIds(cell_id);
	for (int i : col) {
		if (cell_id == i) { continue; } 
		std::vector cell = puzzle.getCell(i);
		if (cell.size() == 1) { continue; }

		if (std::find(cell.begin(), cell.end(), value) != cell.end()) {
			cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
			puzzle.updateCell(i, cell);
			std::cout << "updated notes: " << value << " removed from cell " << i << " : col" << '\n';
		}
	}

	std::vector<int> box = puzzle.getBoxIds(cell_id);
	for (int i : box) {
		if (cell_id == i) { continue; } 
		std::vector cell = puzzle.getCell(i);
		if (cell.size() == 1) { continue; }

		if (std::find(cell.begin(), cell.end(), value) != cell.end()) {
			cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
			puzzle.updateCell(i, cell);
			std::cout << "updated notes: " << value << " removed from cell " << i << " : box" << '\n';
		}
	}
}

void Solver::updateNakedPairs()
{
	for (int i = 1; i <= 73; i += 9) { findNakedPairs(i, "row"); } 
	
	for (int i = 1; i <= 9; i++) { findNakedPairs(i, "col"); }
	
	std::vector<int> box_ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 };
	for (auto i : box_ids) { findNakedPairs(i, "box"); }

}


// searches for matching pairs, and removes those possibilites from the other cells in it's module
void Solver::findNakedPairs(int index, std::string mod_type)
{
	std::vector<int> module{};
	if (mod_type == "row") { module = puzzle.getRowIds(index); }
	if (mod_type == "col") { module = puzzle.getColIds(index); }
	if (mod_type == "box") { module = puzzle.getBoxIds(index); }
	
	for (int i : module) {
		std::vector c1 = puzzle.getCell(i);
		for (int j : module) {
			if (i == j) { continue; }
			std::vector c2 = puzzle.getCell(j);
			if ((c1 == c2) and (c2.size() == 2)) { // if they are a matching pair
				removeNakedPair(i, j, c2, module); // remove that pair from the other cells in row
			}
		}
	}
}

// removes the numbers in a matching pair from every cell in the module, except the cells the pair is 
void Solver::removeNakedPair(int p1, int p2, std::vector<int> pair, std::vector<int> module)
{
	for (int i : module) {
		if (i == p1 or i == p2) { continue; }
		
		std::vector<int> cell = puzzle.getCell(i);
		if (cell.size() == 1) { continue; }
		
		std::vector<int> updated{};
		std::sort(cell.begin(), cell.end());
		std::sort(pair.begin(), pair.end());
		std::set_difference(cell.begin(), cell.end(), pair.begin(), pair.end(), std::inserter(updated, updated.begin()));
		
		if (updated.size() != 0) {
			puzzle.updateCell(i, updated);
			std::cout << "naked pair " << pair[0] << "+" << pair[1] << " removed in cell " << i << '\n';
		}
		else { continue; }		
	}
}

// searches for matching triplets, and removes those possibilites from the other cells in it's module
void Solver::updateNakedTriples()
{
	for (int i = 1; i <= 73; i += 9) {
		removeNakedTriples(i, "row");
	}

	for (int i = 1; i <= 9; i++) {
		removeNakedTriples(i, "col");
	}

	std::vector<int> box_ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 };
	for (auto i : box_ids) {
		removeNakedTriples(i, "box");
	}
}

// the world's most nested function
void Solver::removeNakedTriples(int index, std::string mod_type)
{
	std::vector<int> module{};
	if (mod_type == "row") { module = puzzle.getRowIds(index); }
	if (mod_type == "col") { module = puzzle.getColIds(index); }
	if (mod_type == "box") { module = puzzle.getBoxIds(index); }

	for (int i : module) {
		std::vector c1 = puzzle.getCell(i);
		if ((c1.size() == 2) or (c1.size() == 3)) {
			
			for (int j : module) {
				if (i == j) { continue; }
				std::vector c2 = puzzle.getCell(j);
				if ((c2.size() == 2) or (c2.size() == 3)) {
					
					for (int k : module) {
						if ((k == i) or (k == j)) { continue; }
						std::vector c3 = puzzle.getCell(k);

						if ((c3.size() == 2) or (c3.size() == 3)) {
							std::set<int> triplet{};
							for (int x : c1) { triplet.insert(x); }
							for (int x : c2) { triplet.insert(x); }
							for (int x : c3) { triplet.insert(x); }
							std::vector<int> vec(triplet.begin(), triplet.end());
							std::sort(vec.begin(), vec.end());

							if (triplet.size() == 3) {
								for (int x : module) {
									if ((x != i) and (x != j) and (x != k)) {

										std::vector cell = puzzle.getCell(x);
										if (cell.size() == 1) { continue; }

										for (int y : vec) {
											if (std::find(cell.begin(), cell.end(), y) != cell.end()) {
												cell.erase(remove(cell.begin(), cell.end(), y), cell.end());
												puzzle.updateCell(x, cell);
												std::cout << "naked triple " << vec[0] << '+' << vec[1] << "+" << vec[2] << " removed: " << y << " in cell " << x << '\n';
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

// iterates through every row, column, and box (module) to find hidden pairs 
void Solver::updateHiddenPairs()
{
	for (int i = 1; i <= 73; i += 9) { 
		isolateHiddenPairs(i, "row");
	}
	for (int i = 1; i <= 9 ; i++) { 
		isolateHiddenPairs(i, "col"); 
	}
	
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
	for (int i : module) {
		std::vector<int> cell = puzzle.getCell(i);
		if (cell.size() > 1) {
			for (int j : cell) {
				found_idx[j].push_back(i);
			}
		}
	}
	for (auto it = found_idx.begin(); it != found_idx.end();)
	{
		if (it->second.size() != 2) 
			it = found_idx.erase(it);
		else
			++it;
	}
	for (auto const& [key1, val1] : found_idx) {
		for (auto const& [key2, val2] : found_idx) {
			if (key1 == key2) { continue; }
			
			std::vector<int> pair{};
			if (val1 == val2) { 
				pair.push_back(key1);
				pair.push_back(key2);
				puzzle.updateCell(val2[0], pair);
				//puzzle.updateCell(val2[1], pair);
				std::cout << "hidden pair " << pair[0] << '+' << pair[1] << " isolated in cell " << val2[0]  << '\n';
			}
		}
	}
}

void Solver::updateHiddenTriples()
{
	for (int i = 1; i <= 73; i += 9) {
		isolateHiddenTriples(i, "row");
	}

	for (int i = 1; i <= 9; i++) {
		isolateHiddenTriples(i, "col");
	}

	std::vector<int> box_ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 };
	for (auto i : box_ids) {
		isolateHiddenTriples(i, "box");
	}
}

void Solver::isolateHiddenTriples(int index, std::string mod_type)
{
	std::vector<int> module{};
	if (mod_type == "row") { module = puzzle.getRowIds(index); }
	if (mod_type == "col") { module = puzzle.getColIds(index); }
	if (mod_type == "box") { module = puzzle.getBoxIds(index); }

	std::map<int, std::vector<int>> found_idx{};
	for (int i : module) {
		std::vector<int> cell = puzzle.getCell(i);
		if (cell.size() > 1) {
			for (int j : cell) {
				found_idx[j].push_back(i);
			}
		}
	}
	
	for (auto it = found_idx.begin(); it != found_idx.end();) 
	{
		if ((it->second.size() != 3) and (it->second.size() != 2))
			it = found_idx.erase(it);
		else
			++it;
	}

	std::set<int> triplet_idxs{};
	std::vector<int> triplet{};
	for (auto const& [key, val] : found_idx) {
		for (int x : val) { triplet_idxs.insert(x); }
		triplet.push_back(key);
	}

	if ((triplet_idxs.size() == 3) and (triplet.size() == 3)) {
		for (int i : triplet_idxs) {
			std::vector<int> cell = puzzle.getCell(i);
			std::vector<int> updated_cell{};

			for (auto num : triplet) {
				if (std::find(cell.begin(), cell.end(), num) != cell.end()) {
					updated_cell.push_back(num);
				}
			}
			if (updated_cell.size() != 0) {
				puzzle.updateCell(i, updated_cell);
				std::cout << "hidden triple " << triplet[0] << '+' << triplet[1] << "+" << triplet[2] << " isolated in cell " << i << '\n';
			}
		}
	}
}
