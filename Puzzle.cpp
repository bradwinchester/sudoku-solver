#include "Puzzle.h"
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



