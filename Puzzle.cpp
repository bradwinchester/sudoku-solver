#include "Puzzle.h"
#include <iostream>
#include <string>
#include <algorithm>

Puzzle::Puzzle() {
	for (int i = 1; i <= 81; i++)
		cells[i] = { 1,2,3,4,5,6,7,8,9 };
}

Puzzle::Puzzle(std::vector<int> data)
{
	for (int i = 1; i <= 81; i++) {
		std::vector<int> cell {};
		if (data[i - 1] == 0) {
			cell = { 1,2,3,4,5,6,7,8,9 };
		}
		else {
			cell = { data[i - 1] };
		}
		cells[i] = cell;
	}
}

Puzzle::~Puzzle() {} // destructor

void Puzzle::updateCell(int cell, std::vector<int> nums)
{
	cells[cell] = nums;
}

const std::vector<int>& Puzzle::getCell(int cell)
{
	return cells[cell];
}

std::map<int, std::vector<int>> Puzzle::getRow(int n)
{
	std::vector<int> row_ids = getRowIds(n);
	std::map<int, std::vector<int>> row{};
	
	for (int i : row_ids) {
		row[i] = cells[i];
	}
	return row;
}

std::map<int, std::vector<int>> Puzzle::getCol(int n)
{
	std::vector<int> col_ids = getColIds(n);
	std::map<int, std::vector<int>> col{};

	for (int i : col_ids) {
		col[i] = cells[i];
	}
	return col;
}

std::map<int, std::vector<int>> Puzzle::getBox(int n)
{
	std::vector<int> box_ids = getBoxIds(n);
	std::map<int, std::vector<int>> box{};

	for (int i : box_ids) {
		box[i] = cells[i];
	}
	return box;
}






// returns the ids for all cells in a cell's row
std::vector<int> Puzzle::getRowIds(int cell) 
{
	if (cell >= 1 and cell <= 9) { return { 1,2,3,4,5,6,7,8,9 }; }
	if (cell >= 10 and cell <= 18) { return { 10,11,12,13,14,15,16,17,18 }; }
	if (cell >= 19 and cell <= 27) { return { 19,20,21,22,23,24,25,26,27}; }
	if (cell >= 28 and cell <= 36) { return { 28,29,30,31,32,33,34,35,36 }; }
	if (cell >= 37 and cell <= 45) { return { 37,38,39,40,41,42,43,44,45 }; }
	if (cell >= 46 and cell <= 54) { return { 46,47,48,49,50,51,52,53,54 }; }
	if (cell >= 55 and cell <= 63) { return { 55,56,57,58,59,60,61,62,63 }; }
	if (cell >= 64 and cell <= 72) { return { 64,65,66,67,68,69,70,71,72 }; }
	if (cell >= 73 and cell <= 81) { return { 73,74,75,76,77,78,79,80,81 }; }
	return { 0 };
}

// returns the ids for all cells in a cell's column 
std::vector<int> Puzzle::getColIds(int cell)
{
	switch (cell)
	{
	case 1: case 10: case 19: case 28: case 37: case 46: case 55: case 64: case 73:
		return { 1,10,19,28,37,46,55,64,73 };
	case 2: case 11: case 20: case 29: case 38: case 47: case 56: case 65: case 74:
		return { 2,11,20,29,38,47,56,65,74 };
	case 3: case 12: case 21: case 30: case 39: case 48: case 57: case 66: case 75:
		return { 3,12,21,30,39,48,57,66,75 };
	case 4: case 13: case 22: case 31: case 40: case 49: case 58: case 67: case 76:
		return { 4,13,22,31,40,49,58,67,76 };
	case 5: case 14: case 23: case 32: case 41: case 50: case 59: case 68: case 77:
		return { 5,14,23,32,41,50,59,68,77 };
	case 6: case 15: case 24: case 33: case 42: case 51: case 60: case 69: case 78:
		return { 6,15,24,33,42,51,60,69,78 };
	case 7: case 16: case 25: case 34: case 43: case 52: case 61: case 70: case 79:
		return { 7,16,25,34,43,52,61,70,79 };
	case 8: case 17: case 26: case 35: case 44: case 53: case 62: case 71: case 80:
		return { 8,17,26,35,44,53,62,71,80 };
	case 9: case 18: case 27: case 36: case 45: case 54: case 63: case 72: case 81:
		return { 9,18,27,36,45,54,63,72,81 };
	default:
		return { 0,0,0,0,0,0,0,0,0 };
	}
}

// returns the ids for all cells in a cell's box
std::vector<int> Puzzle::getBoxIds(int cell)
{
	switch (cell)
	{
	case 1: case 2: case 3: case 10: case 11: case 12: case 19: case 20: case 21:
		return { 1,2,3,10,11,12,19,20,21 };
	case 4: case 5: case 6: case 13: case 14: case 15: case 22: case 23: case 24:
		return { 4,5,6,13,14,15,22,23,24 };
	case 7: case 8: case 9: case 16: case 17: case 18: case 25: case 26: case 27:
		return { 7,8,9,16,17,18,25,26,27 };
	case 28: case 29: case 30: case 37: case 38: case 39: case 46: case 47: case 48:
		return { 28,29,30,37,38,39,46,47,48 };
	case 31: case 32: case 33: case 40: case 41: case 42: case 49: case 50: case 51:
		return { 31,32,33,40,41,42,49,50,51 };
	case 34: case 35: case 36: case 43: case 44: case 45: case 52: case 53: case 54:
		return { 34,35,36,43,44,45,52,53,54 };
	case 55: case 56: case 57: case 64: case 65: case 66: case 73: case 74: case 75:
		return { 55,56,57,64,65,66,73,74,75 };
	case 58: case 59: case 60: case 67: case 68: case 69: case 76: case 77: case 78:
		return { 58,59,60,67,68,69,76,77,78 };
	case 61: case 62: case 63: case 70: case 71: case 72: case 79: case 80: case 81:
		return { 61,62,63,70,71,72,79,80,81 };
	default:
		return { 0,0,0,0,0,0,0,0,0 };
	}
}

void Puzzle::printPuzzle()
{
	for (auto const& [key, val] : cells) {
		if (val.size() > 1) {
			std::cout << '0';
		}
		else {
			for (int y : val) {
				std::cout << std::to_string(y) + " ";
			}
		}
		if (key % 3 == 0) { std::cout << ' '; }
		if (key % 9 == 0) { std::cout << '\n'; }
		if (key % 27 == 0) { std::cout << '\n'; }
	}
}

void Puzzle::printPuzzleWithNotes()
{
	std::cout << "-------------------------------------------------------" << '\n';
	std::vector<int> vec{};
	for (int i = 0; i < 81; i += 9) {				
		for (int j = 1; j <= 9; j++) {
			vec = cells[i + j];
			if (j == 1) { std::cout << "| "; }
			if (std::find(vec.begin(), vec.end(), 1) != vec.end()) { std::cout << "1"; }
			else { std::cout << " "; }
			if (std::find(vec.begin(), vec.end(), 2) != vec.end()) { std::cout << "2"; }
			else { std::cout << " "; }
			if (std::find(vec.begin(), vec.end(), 3) != vec.end()) { std::cout << "3"; }
			else { std::cout << " "; }
			std::cout << " | ";
		}
		std::cout << '\n';

		for (int j = 1; j <= 9; j++) {
			vec = cells[i + j];
			if (j == 1) { std::cout << "| "; }
			if (std::find(vec.begin(), vec.end(), 4) != vec.end()) { std::cout << "4"; }
			else { std::cout << " "; }
			if (std::find(vec.begin(), vec.end(), 5) != vec.end()) { std::cout << "5"; }
			else { std::cout << " "; }
			if (std::find(vec.begin(), vec.end(), 6) != vec.end()) { std::cout << "6"; }
			else { std::cout << " "; }
			std::cout << " | ";
		}
		std::cout << '\n';

		for (int j = 1; j <= 9; j++) {
			vec = cells[i + j];
			if (j == 1) { std::cout << "| "; }
			if (std::find(vec.begin(), vec.end(), 7) != vec.end()) { std::cout << "7"; }
			else { std::cout << " "; }
			if (std::find(vec.begin(), vec.end(), 8) != vec.end()) { std::cout << "8"; }
			else { std::cout << " "; }
			if (std::find(vec.begin(), vec.end(), 9) != vec.end()) { std::cout << "9"; }
			else { std::cout << " "; }
			std::cout << " | ";

			if (j == 9) { std::cout << '\n' << "-------------------------------------------------------"; }
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

	