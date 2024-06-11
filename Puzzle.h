#pragma once
#include <map>
#include <vector>

class Puzzle
{
public:
	// constructors
	Puzzle();
	Puzzle(std::vector<int> data);
	~Puzzle();
	
	// setters & getters
	void updateCell(int cell, std::vector<int> nums);
	const std::vector<int>& getCell(int cell);

	std::map<int, std::vector<int>> getRow(int n);
	std::map<int, std::vector<int>> getCol(int n);
	std::map<int, std::vector<int>> getBox(int n);

	std::vector<int> getRowIds(int cell);
	std::vector<int> getColIds(int cell);
	std::vector<int> getBoxIds(int cell);
	

	// misc functions
	void printPuzzle();
	void printPuzzleWithNotes();

private:
	std::map<int, std::vector<int>> cells{};
};

