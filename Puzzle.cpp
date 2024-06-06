#include "Puzzle.h"
#include <iostream>
#include <string>

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



