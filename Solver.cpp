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

// enable or disable text based output of the solver
bool output = true;

// iteratively attempts to solve the puzzle using the algorithms
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
	
	bool rows_solved = false;
	std::vector<int> row{};
	for (int i = 1; i <= 73; i += 9) {
		std::vector<int> row_ids = puzzle.getRowIds(i);

		for (int j : row_ids) {
			std::vector<int> cell = puzzle.getCell(j);
			if (cell.empty()) {
				if (output) { std::cout << "Error! Cell " << j << " is blank!" << '\n'; }
				return false;
			}
			if (cell.size() > 1) {
				if (output) { std::cout << "Puzzle not yet solved. Cell " << j << " is incomplete." << '\n'; }
				return false;
			}
			if (cell.size() == 1) { row.push_back(cell[0]); }
		}
	}
	std::sort(row.begin(), row.end());
	if ((row.size() == 9) and (row != nums)) {
		if (output) { std::cout << "Invalid Solution!" << '\n'; }
		return false;
	}
	rows_solved = true; 


	bool cols_solved = false;
	std::vector<int> col{};
	for (int i = 1; i <= 9; i++) {
		std::vector<int> col_ids = puzzle.getColIds(i);

		for (int j : col_ids) {
			std::vector<int> cell = puzzle.getCell(j);
			if (cell.empty()) {
				if (output) { std::cout << "Error! Cell " << j << " is blank!" << '\n'; }
				return false;
			}
			if (cell.size() > 1) {
				if (output) { std::cout << "Puzzle not yet solved. Cell " << j << " is incomplete." << '\n'; }
				return false;
			}
			if (cell.size() == 1) { col.push_back(cell[0]); }
		}
		
		
	}
	std::sort(col.begin(), col.end());
	if ((col.size() == 9) and (col != nums)) {
		if (output) { std::cout << "Invalid Solution!" << '\n'; }
		return false;
	}
	cols_solved = true;
	
	
	bool boxs_solved = false;
	std::vector<int> box{};
	std::vector<int> ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 };
	for (auto i : ids) {
		std::vector<int> box_ids = puzzle.getBoxIds(i);

		for (int j : box_ids) {
			std::vector<int> cell = puzzle.getCell(j);
			if (cell.empty()) {
				if (output) { std::cout << "Error! Cell " << j << " is blank!" << '\n'; }
				return false;
			}
			if (cell.size() > 1) {
				if (output) { std::cout << "Puzzle not yet solved. Cell " << j << " is incomplete." << '\n'; }
				return false;
			}
			if (cell.size() == 1) { box.push_back(cell[0]); }
		}
	}
	std::sort(box.begin(), box.end());
	if ((box.size() == 9) and (box != nums)) {
		if (output) { std::cout << "Invalid Solution!" << '\n'; }
		return false;
	}
	boxs_solved = true; 
	

	if (rows_solved and cols_solved and boxs_solved) {
		if (output) { std::cout << "Puzzle Solved!" << '\n'; }
		return true;
	}
	else {
		if (output) { std::cout << "Puzzle not yet solved..." << '\n'; }
		return false;
	}
}

// removes the already solved cells as a possibility from the relevant modules
void Solver::updateNotes()
{
	for (int i = 1; i <= 81; i++) { // for each cell in the puzzle
		auto cell = puzzle.getCell(i);
		if (cell.size() == 1) { // if cell is solved
			int num = cell[0];
			removeNumberFromModule(i, num); // remove that number from every module it is a part of 
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
		if (cell.size() == 1) { continue; } // skip if cell is solved

		if (std::find(cell.begin(), cell.end(), value) != cell.end()) { // if number is found in the cell
			cell.erase(remove(cell.begin(), cell.end(), value), cell.end()); // remove it and update the cell
			puzzle.updateCell(i, cell);

			if (output) { std::cout << "updated notes: " << value << " removed from cell " << i << " : row" << '\n'; }
		}
	}

	std::vector<int> col = puzzle.getColIds(cell_id); // repeat the process for the column the cell is in
	for (int i : col) {
		if (cell_id == i) { continue; } 
		std::vector cell = puzzle.getCell(i);
		if (cell.size() == 1) { continue; } 

		if (std::find(cell.begin(), cell.end(), value) != cell.end()) {
			cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
			puzzle.updateCell(i, cell);
			
			if (output) { std::cout << "updated notes: " << value << " removed from cell " << i << " : col" << '\n'; }
		}
	}

	std::vector<int> box = puzzle.getBoxIds(cell_id); // repeat the process for the box the cell is in
	for (int i : box) {
		if (cell_id == i) { continue; } 
		std::vector cell = puzzle.getCell(i);
		if (cell.size() == 1) { continue; }

		if (std::find(cell.begin(), cell.end(), value) != cell.end()) {
			cell.erase(remove(cell.begin(), cell.end(), value), cell.end());
			puzzle.updateCell(i, cell);
			
			if (output) { std::cout << "updated notes: " << value << " removed from cell " << i << " : box" << '\n'; }
		}
	}
}

// iterates through every module to find naked pairs
void Solver::updateNakedPairs()
{
	for (int i = 1; i <= 73; i += 9) { // first id of each row 
		findNakedPairs(i, "row"); 
	} 
	
	for (int i = 1; i <= 9; i++) {  // first id of each col
		findNakedPairs(i, "col");
	}
	
	std::vector<int> box_ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 }; // first id of each box
	for (auto i : box_ids) { 
		findNakedPairs(i, "box"); 
	}

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
		if (i == p1 or i == p2) { continue; } // skip if cell is a member of the pair
		
		std::vector<int> cell = puzzle.getCell(i);
		if (cell.size() == 1) { continue; } // skip if cell is already solved
		
		std::vector<int> updated{};
		std::sort(cell.begin(), cell.end());
		std::sort(pair.begin(), pair.end());
		
		// remove values of the pair from the cell's options
		std::set_difference(cell.begin(), cell.end(), pair.begin(), pair.end(), std::inserter(updated, updated.begin()));
		
		if (updated.size() != 0) {
			
			if (output) { std::cout << "naked pair " << pair[0] << "+" << pair[1] << " removed in cell " << i << '\n'; }
			puzzle.updateCell(i, updated);
		}
		else { continue; }		
	}
}

// searches for matching triplets, and removes those possibilites from the other cells in it's module
void Solver::updateNakedTriples()
{
	for (int i = 1; i <= 73; i += 9) { // first id of each row 
		removeNakedTriples(i, "row");
	}

	for (int i = 1; i <= 9; i++) { // first id of each col
		removeNakedTriples(i, "col");
	}

	std::vector<int> box_ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 }; // first id of each box 
	for (auto i : box_ids) {
		removeNakedTriples(i, "box");
	}
}

// locates naked triples within a module and removes those numbers as possibilities from all other cells in the module
void Solver::removeNakedTriples(int index, std::string mod_type) // the world's most nested function
{
	std::vector<int> module{};
	if (mod_type == "row") { module = puzzle.getRowIds(index); }
	if (mod_type == "col") { module = puzzle.getColIds(index); }
	if (mod_type == "box") { module = puzzle.getBoxIds(index); }

	for (int i : module) {
		std::vector c1 = puzzle.getCell(i);
		if ((c1.size() == 2) or (c1.size() == 3)) { // only interested in cells that have two or three available options
			
			for (int j : module) {
				if (i == j) { continue; } // don't compare a cell to itself
				std::vector c2 = puzzle.getCell(j);
				if ((c2.size() == 2) or (c2.size() == 3)) {
					
					for (int k : module) {
						if ((k == i) or (k == j)) { continue; } // don't compare a cell to itself
						std::vector c3 = puzzle.getCell(k);
						if ((c3.size() == 2) or (c3.size() == 3)) { 
							
							std::set<int> triplet{}; // used a set to ensure there are only three distinct numbers total, aka, a triplet)
							for (int x : c1) { triplet.insert(x); }
							for (int x : c2) { triplet.insert(x); }
							for (int x : c3) { triplet.insert(x); }
							std::vector<int> vec(triplet.begin(), triplet.end());
							std::sort(vec.begin(), vec.end());

							if (triplet.size() == 3) { // check if it is a triplet
								for (int x : module) {
									if ((x != i) and (x != j) and (x != k)) { // ignore cells where the triplet occurs

										std::vector cell = puzzle.getCell(x);
										if (cell.size() == 1) { continue; } // ignore cells that are already solved

										for (int y : vec) { // for all cells in the module, except where the triplet occurs
											if (std::find(cell.begin(), cell.end(), y) != cell.end()) { // if a number in the triplet found 
												cell.erase(remove(cell.begin(), cell.end(), y), cell.end()); // remove it 
												puzzle.updateCell(x, cell); 

												if (output) { std::cout << "naked triple " << vec[0] << '+' << vec[1] << "+" << vec[2] << " removed: " << y << " in cell " << x << '\n'; }
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

// iterates through every module to find hidden pairs 
void Solver::updateHiddenPairs()
{
	for (int i = 1; i <= 73; i += 9) { // first id of each row 
		isolateHiddenPairs(i, "row");
	}
	for (int i = 1; i <= 9 ; i++) { // first id of each col 
		isolateHiddenPairs(i, "col"); 
	}
	
	std::vector<int> box_ids = { 1, 4, 7, 28, 31, 34, 55, 58, 61 }; // first id of each box 
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

	std::map<int, std::vector<int>> found_idx{}; // records the index each time a number occurs, for every number in the module
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
		if (it->second.size() != 2) // remove any numbers that don't occur exactly twice, since they cannot be part of a pair
			it = found_idx.erase(it);
		else
			++it;
	}
	for (auto const& [key1, val1] : found_idx) {
		for (auto const& [key2, val2] : found_idx) {
			if (key1 == key2) { continue; } // don't compare a cell to itself
			
			std::vector<int> pair{};
			if (val1 == val2) { // if it is a hidden pair, update the possibilities to be only that pair in each cell
				pair.push_back(key1);
				pair.push_back(key2);
				puzzle.updateCell(val2[0], pair);
				puzzle.updateCell(val2[1], pair);

				if (output) { std::cout << "hidden pair " << pair[0] << '+' << pair[1] << " isolated in cell " << val2[0] << '\n'; }
			}
		}
	}
}

// iterates through every module to find hidden triples 
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

// locates hidden triples within a module and removes all other numbers from the cells where it occurs
void Solver::isolateHiddenTriples(int index, std::string mod_type)
{
	std::vector<int> module{};
	if (mod_type == "row") { module = puzzle.getRowIds(index); }
	if (mod_type == "col") { module = puzzle.getColIds(index); }
	if (mod_type == "box") { module = puzzle.getBoxIds(index); }

	std::map<int, std::vector<int>> found_idx{}; // records the index each time a number occurs, for every number in the module
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
		if ((it->second.size() != 3) and (it->second.size() != 2)) // remove any numbers that don't occur 2 or 3 times, since they cannot be part of a triple
			it = found_idx.erase(it);
		else
			++it;
	}

	std::set<int> triplet_idxs{};
	std::vector<int> triplet{};
	for (auto const& [key, val] : found_idx) {
		for (int x : val) { triplet_idxs.insert(x); } // get the indexes of the hidden triple 
		triplet.push_back(key);
	}

	if ((triplet_idxs.size() == 3) and (triplet.size() == 3)) {
		for (int i : triplet_idxs) {
			std::vector<int> cell = puzzle.getCell(i);
			std::vector<int> updated_cell{};

			for (auto num : triplet) {
				if (std::find(cell.begin(), cell.end(), num) != cell.end()) { // replace triplet cells with only the members of the triplet which it already contained 
					updated_cell.push_back(num);
				}
			}
			//if ((updated_cell.size() != 0) and (updated_cell.size() != cell.size())) {
			if (updated_cell.size() != 0) {
				puzzle.updateCell(i, updated_cell);
				
				if (output) { std::cout << "hidden triple " << triplet[0] << '+' << triplet[1] << "+" << triplet[2] << " isolated in cell " << i << '\n'; }
			}
		}
	}
}
