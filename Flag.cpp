#include "Flag.h"
Flags::Flags() = default;

const std::vector<int>& Flags::getFlag(std::string cell_id) const
{
	return m_flags.at(cell_id);
}

void Flags::setFlag(std::string cell_id, std::vector<int> updated_flag)
{
	m_flags[cell_id] = updated_flag;
}




