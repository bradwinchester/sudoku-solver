#include "Solver.h"

Solver::Solver(Puzzle puzzle)
	: m_puzzle { puzzle } 
{
	m_notes.refreshNotes(m_puzzle);
	solve();
	m_puzzle.printPuzzle();
}

void Solver::solve()
{
	m_notes.lastRemainingCell(m_puzzle);
}

bool Solver::checkValidSolution()
{
	
	
	return false;
}







