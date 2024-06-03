#include <iostream>
#include <Puzzle.h>
#include <Solver.h>
#include <Note.h>
#include <array>
#include <Numeric>
#include <algorithm>

int main()
{
    Array2d test_data = {{
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

    Puzzle puzzle = { 1, test_data };
    Solver solver = { puzzle };
    
    return 0;
}

