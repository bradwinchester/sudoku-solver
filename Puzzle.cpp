#include "Puzzle.h"
#include <iostream>
#include <array>

Puzzle::Puzzle() = default; // default constructor 
Puzzle::Puzzle(int id, Array2d data)
    : m_id{ id }, m_data{ data } {}
Puzzle::~Puzzle() {} // destructor

const Array2d& Puzzle::getData() const { return m_data; }
void Puzzle::setData(Array2d data) { m_data = data; }

const int& Puzzle::getCell(int i, int j) const { return m_data[i-1][j-1]; }
void Puzzle::setCell(int i, int j, int val) { m_data[i-1][j-1] = val; }

const std::array<int, 9>& Puzzle::getRow(int x) const { return m_data[x - 1]; }
void Puzzle::setRow(int x, std::array<int, 9> row) { m_data[x - 1] = row; }

const std::array<int, 9>& Puzzle::getCol(int x) const
{
    const std::array col = { 
        m_data[0][x - 1],
        m_data[1][x - 1],
        m_data[2][x - 1],
        m_data[3][x - 1],
        m_data[4][x - 1],
        m_data[5][x - 1],
        m_data[6][x - 1],
        m_data[7][x - 1],
        m_data[8][x - 1]
    }; return col;
}
void Puzzle::setCol(int col, std::array<int, 9> new_col) 
{
    for (int i = 0; i < 9; i++) { m_data[i][col - 1] = new_col[i]; }
}

const std::array<int, 9>& Puzzle::getBox(int x) const
{
    std::array<int, 9> box;
    for (int i = 0; i < 3; i++)
    {
        switch (x)
        {
        case 1:
            box[i] = m_data[0][i];
            box[i + 3] = m_data[1][i];
            box[i + 6] = m_data[2][i];
            break;
        case 2:
            box[i] = m_data[0][i + 3];
            box[i + 3] = m_data[1][i + 3];
            box[i + 6] = m_data[2][i + 3];
            break;
        case 3:
            box[i] = m_data[0][i + 6];
            box[i + 3] = m_data[1][i + 6];
            box[i + 6] = m_data[2][i + 6];
            break;
        case 4:
            box[i] = m_data[3][i];
            box[i + 3] = m_data[4][i];
            box[i + 6] = m_data[5][i];
            break;
        case 5:
            box[i] = m_data[3][i + 3];
            box[i + 3] = m_data[4][i + 3];
            box[i + 6] = m_data[5][i + 3];
            break;
        case 6:
            box[i] = m_data[3][i + 6];
            box[i + 3] = m_data[4][i + 6];
            box[i + 6] = m_data[5][i + 6];
            break;
        case 7:
            box[i] = m_data[6][i];
            box[i + 3] = m_data[7][i];
            box[i + 6] = m_data[8][i];
            break;
        case 8:
            box[i] = m_data[6][i + 3];
            box[i + 3] = m_data[7][i + 3];
            box[i + 6] = m_data[8][i + 3];
            break;
        case 9:
            box[i] = m_data[6][i + 6];
            box[i + 3] = m_data[7][i + 6];
            box[i + 6] = m_data[8][i + 6];
            break;
        }
    } return box;
}

void Puzzle::setBox(int box, std::array<int, 9> new_box) 
{
    for (int i = 0; i < 3; i++)
    {
        switch (box)
        {
        case 1:
            m_data[0][i] = new_box[i];
            m_data[1][i] = new_box[i + 3];
            m_data[2][i] = new_box[i + 6];
            break;
        case 2:
            m_data[0][i + 3] = new_box[i];
            m_data[1][i + 3] = new_box[i + 3];
            m_data[2][i + 3] = new_box[i + 6];
            break;
        case 3:
            m_data[0][i + 6] = new_box[i];
            m_data[1][i + 6] = new_box[i + 3];
            m_data[2][i + 6] = new_box[i + 6];
            break;
        case 4:
            m_data[3][i] = new_box[i];
            m_data[4][i] = new_box[i + 3];
            m_data[5][i] = new_box[i + 6];
            break;
        case 5:
            m_data[3][i + 3] = new_box[i];
            m_data[4][i + 3] = new_box[i + 3];
            m_data[5][i + 3] = new_box[i + 6];
            break;
        case 6:
            m_data[3][i + 6] = new_box[i];
            m_data[4][i + 6] = new_box[i + 3];
            m_data[5][i + 6] = new_box[i + 6];
            break;
        case 7:
            m_data[6][i] = new_box[i];
            m_data[7][i] = new_box[i + 3];
            m_data[8][i] = new_box[i + 6];
            break;
        case 8:
            m_data[6][i + 3] = new_box[i];
            m_data[7][i + 3] = new_box[i + 3];
            m_data[8][i + 3] = new_box[i + 6];
            break;
        case 9:
            m_data[6][i + 6] = new_box[i];
            m_data[7][i + 6] = new_box[i + 3];
            m_data[8][i + 6] = new_box[i + 6];
            break;
        }
    }
}

void Puzzle::printPuzzle()
{
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            std::cout << ' ' << getCell(i, j);
            if (j % 3 == 0) { std::cout << ' '; }
        }
        std::cout << '\n';
        if (i % 3 == 0) { std::cout << '\n'; }
    }
}



int Puzzle::getBoxNumber(int i, int j)
{
    if (i <= 3) 
    {
        if (j <= 3)
            return 1;
        if (j >= 4 && j <= 6)
            return 2;
        if (j >= 7)
            return 3; 
        
    }
    if (i >= 4 && i <= 6) {
        if (j <= 3)
            return 4;
        if (j >= 4 && j <= 6)
            return 5;
        if (j >= 7)
            return 6;
        
    }
    if (i >= 7)
    {
        if (j <= 3)
            return 7;
        if (j >= 4 && j <= 6)
            return 8;
        if (j >= 7)
            return 9;
        
    }
    

}
