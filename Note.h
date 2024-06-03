#pragma once
#include <array>
#include <vector>
#include <map>
#include <string>

class Note
{
private:
	std::map < std::string, std::vector<int>> m_notes;

public:
	Note();
	const std::vector<int>& getNote(std::string cell_id) const;
	void setNote(std::string cell_id, std::vector<int> updated_note);
};

