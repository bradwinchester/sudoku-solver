#pragma once
#include <array>
#include <vector>
#include <map>
#include <string>

class Flags
{
private:
	std::map < std::string, std::vector<int>> m_flags;

public:
	Flags();
	const std::vector<int>& getFlag(std::string cell_id) const;
	void setFlag(std::string cell_id, std::vector<int> updated_flag);
};

