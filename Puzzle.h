#pragma once
#include <array>

using Array2d = std::array<std::array<int, 9>, 9>;

class Puzzle
{
private:
	int m_id {};
	Array2d m_data = {{
		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0},

		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0},

		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0},
		{0,0,0, 0,0,0, 0,0,0}} 
	};
		
public:
	// constructors
	Puzzle();
	Puzzle(int id, Array2d data);				
	~Puzzle();

	// accessors 
	const Array2d& getData() const;
	const int& getCell(int i, int j) const;
	const std::array<int, 9>& getRow(int x) const;
	const std::array<int, 9>& getCol(int x) const;
	const std::array<int, 9>& getBox(int x) const;

	// mutators
	void setData(Array2d data);
	void setCell(int i, int j, int val);
	void setRow(int col, std::array<int, 9> new_row);
	void setCol(int row, std::array<int, 9> new_col);
	void setBox(int box, std::array<int, 9> new_box);


	// other functions
	void printPuzzle();
	int getBoxNumber(int i, int j);
};


