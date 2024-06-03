#include "Note.h"
Note::Note() = default;

const std::vector<int>& Note::getNote(std::string cell_id) const
{
	return m_notes.at(cell_id);
}

void Note::setNote(std::string cell_id, std::vector<int> updated_flag)
{
	m_notes[cell_id] = updated_flag;
}




