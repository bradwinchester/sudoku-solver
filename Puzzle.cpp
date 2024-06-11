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

std::vector<int> Puzzle::getCell(int cell)
{
	return cells[cell];
}

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

	