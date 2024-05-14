#include <iostream>
#include <Puzzle.h>
#include <array>

int main()
{
    Array2d test_data = {{
        {0,7,5, 4,1,6, 3,8,9},
        {1,9,8, 2,3,7, 4,5,6},
        {3,6,4, 9,8,5, 7,1,2},

        {7,8,3, 5,6,1, 2,9,4},
        {4,1,9, 7,2,3, 8,6,5},
        {6,5,2, 8,4,9, 1,7,3},

        {9,4,6, 3,7,8, 5,2,1},
        {5,2,7, 1,9,4, 6,3,8},
        {8,3,1, 6,5,2, 9,4,7}
    }};

    Puzzle test_puzzle = { 1, test_data };
    test_puzzle.printPuzzle();
    std::cout << '\n';

    std::array<int, 9> new_row = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    test_puzzle.setBox(9, new_row);
    test_puzzle.printPuzzle();

    
   

    return 0;
}

