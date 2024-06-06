#pragma once
#include <map>
#include <vector>

class Puzzle
{
public:
	std::map<int, std::vector<int>> cells{};

	// constructors
	Puzzle();
	Puzzle(std::vector<int> data);
	~Puzzle();



};

