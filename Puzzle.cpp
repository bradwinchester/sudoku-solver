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
	std::vector<int> vec{};
	for (int i = 0; i < 81; i += 9) { // 0, 9, 18, 27, 36, 45, 54, 63, 72 				
		for (int j = 1; j <= 9; j++) {
			vec = cells[i + j];
			if (vec.size() == 1) { std::cout << std::to_string(vec[0]) + ' ' + std::to_string(vec[0]) + ' ' + std::to_string(vec[0]); }
			else { std::cout << std::to_string(vec[0]) + ' ' + std::to_string(vec[1]) + ' ' + std::to_string(vec[2]); }
			if (j == 3 or j == 6) { std::cout << "  |  "; }
			else { std::cout << "   "; }
		}
		std::cout << '\n';
		for (int j = 1; j <= 9; j++) {
			vec = cells[i + j];
			if (vec.size() == 1) { std::cout << std::to_string(vec[0]) + ' ' + std::to_string(vec[0]) + ' ' + std::to_string(vec[0]); }
			else { std::cout << std::to_string(vec[3]) + ' ' + std::to_string(vec[4]) + ' ' + std::to_string(vec[5]); }
			if (j == 3 or j == 6) { std::cout << "  |  "; }
			else { std::cout << "   "; }
		}
		std::cout << '\n';
		for (int j = 1; j <= 9; j++) {
			vec = cells[i + j];
			if (vec.size() == 1) { std::cout << std::to_string(vec[0]) + ' ' + std::to_string(vec[0]) + ' ' + std::to_string(vec[0]); }
			else { std::cout << std::to_string(vec[6]) + ' ' + std::to_string(vec[7]) + ' ' + std::to_string(vec[8]); }
			if (j == 3 or j == 6) { std::cout << "  |  "; }
			else { std::cout << "   "; }
		}
		std::cout << '\n';
		if (i == 72) { break; }
		if (i == 18 or i ==  45) { std::cout << "-------------------------------------------------------------------------" << '\n'; }
		else { std::cout << "                       |                         |                        " << '\n'; }
		
	}
}

	




		/*
		std::vector c1 = cells[i + 1];
		std::vector c2 = cells[i + 2];
		std::vector c3 = cells[i + 3];
		std::vector c4 = cells[i + 4];
		std::vector c5 = cells[i + 5];
		std::vector c6 = cells[i + 6];
		std::vector c7 = cells[i + 7];
		std::vector c8 = cells[i + 8];
		std::vector c9 = cells[i + 9];

		if (c1.size() == 1) { std::cout << std::to_string(c1[0]) + ' ' + std::to_string(c1[0]) + ' ' + std::to_string(c1[0]) + "    "; }
		else { std::cout << std::to_string(c1[i]) + ' ' + std::to_string(c1[i + 1]) + ' ' + std::to_string(c1[i + 2]) + "    "; }

		if (c2.size() == 1) { std::cout << std::to_string(c2[0]) + ' ' + std::to_string(c2[0]) + ' ' + std::to_string(c2[0]) + "    "; }
		else { std::cout << std::to_string(c2[i]) + ' ' + std::to_string(c2[i + 1]) + ' ' + std::to_string(c2[i + 2]) + "    "; }

		if (c3.size() == 1) { std::cout << std::to_string(c3[0]) + ' ' + std::to_string(c3[0]) + ' ' + std::to_string(c3[0]) + "    "; }
		else { std::cout << std::to_string(c3[i]) + ' ' + std::to_string(c3[i + 1]) + ' ' + std::to_string(c3[i + 2]) + "    "; }
		
		if (c4.size() == 1) { std::cout << std::to_string(c4[0]) + ' ' + std::to_string(c4[0]) + ' ' + std::to_string(c4[0]) + "    "; }
		else { std::cout << std::to_string(c4[i]) + ' ' + std::to_string(c4[i + 1]) + ' ' + std::to_string(c4[i + 2]) + "    "; }

		if (c5.size() == 1) { std::cout << std::to_string(c5[0]) + ' ' + std::to_string(c5[0]) + ' ' + std::to_string(c5[0]) + "    "; }
		else { std::cout << std::to_string(c5[i]) + ' ' + std::to_string(c5[i + 1]) + ' ' + std::to_string(c5[i + 2]) + "    "; }

		if (c6.size() == 1) { std::cout << std::to_string(c6[0]) + ' ' + std::to_string(c6[0]) + ' ' + std::to_string(c6[0]) + "    "; }
		else { std::cout << std::to_string(c6[i]) + ' ' + std::to_string(c6[i + 1]) + ' ' + std::to_string(c6[i + 2]) + "    "; }

		if (c7.size() == 1) { std::cout << std::to_string(c7[0]) + ' ' + std::to_string(c7[0]) + ' ' + std::to_string(c7[0]) + "    "; }
		else { std::cout << std::to_string(c7[i]) + ' ' + std::to_string(c7[i + 1]) + ' ' + std::to_string(c7[i + 2]) + "    "; }

		if (c8.size() == 1) { std::cout << std::to_string(c8[0]) + ' ' + std::to_string(c8[0]) + ' ' + std::to_string(c8[0]) + "    "; }
		else { std::cout << std::to_string(c8[i]) + ' ' + std::to_string(c8[i + 1]) + ' ' + std::to_string(c8[i + 2]) + "    "; }

		if (c9.size() == 1) { std::cout << std::to_string(c9[0]) + ' ' + std::to_string(c9[0]) + ' ' + std::to_string(c9[0]) + "    "; }
		else { std::cout << std::to_string(c9[i]) + ' ' + std::to_string(c9[i + 1]) + ' ' + std::to_string(c9[i + 2]) + "    "; }
		std::cout << '\n';
		

		
		
		if (c1.size() == 1) { std::cout << std::to_string(c1[0]) + ' ' + std::to_string(c1[0]) + ' ' + std::to_string(c1[0]) + "    "; }
		else { std::cout << std::to_string(c1[i + 3]) + ' ' + std::to_string(c1[i + 4]) + ' ' + std::to_string(c1[i + 5]) + "    "; }

		if (c2.size() == 1) { std::cout << std::to_string(c2[0]) + ' ' + std::to_string(c2[0]) + ' ' + std::to_string(c2[0]) + "    "; }
		else { std::cout << std::to_string(c2[i + 3]) + ' ' + std::to_string(c2[i + 4]) + ' ' + std::to_string(c2[i + 5]) + "    "; }

		if (c3.size() == 1) { std::cout << std::to_string(c3[0]) + ' ' + std::to_string(c3[0]) + ' ' + std::to_string(c3[0]) + "    "; }
		else { std::cout << std::to_string(c3[i + 3]) + ' ' + std::to_string(c3[i + 4]) + ' ' + std::to_string(c3[i + 5]) + "    "; }

		if (c1.size() == 1) { std::cout << std::to_string(c1[0]) + ' ' + std::to_string(c1[0]) + ' ' + std::to_string(c1[0]) + "    "; }
		else { std::cout << std::to_string(c1[i + 6]) + ' ' + std::to_string(c1[i + 7]) + ' ' + std::to_string(c1[i + 8]) + "    "; }

		if (c2.size() == 1) { std::cout << std::to_string(c2[0]) + ' ' + std::to_string(c2[0]) + ' ' + std::to_string(c2[0]) + "    "; }
		else { std::cout << std::to_string(c2[i + 6]) + ' ' + std::to_string(c2[i + 7]) + ' ' + std::to_string(c2[i + 8]) + "    "; }

		if (c3.size() == 1) { std::cout << std::to_string(c3[0]) + ' ' + std::to_string(c3[0]) + ' ' + std::to_string(c3[0]) + "    "; }
		else { std::cout << std::to_string(c3[i + 6]) + ' ' + std::to_string(c3[i + 7]) + ' ' + std::to_string(c3[i + 8]) + "    "; }



*/

	/*	if (r1.size() == 1) { std::cout << std::to_string(r1[0]) + ' '; }
		else {
			std::cout << std::to_string(vec[i]) + ' ';
		}
		if ((i+1) % 3 == 0) { std::cout << '\n'; }*/
	




