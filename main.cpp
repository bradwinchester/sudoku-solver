#include "Puzzle.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    std::vector<int> vec = {
        9,9,9,9,9,9,9,9,0,
        9,9,9,9,9,9,9,9,1,
        9,9,9,9,9,9,9,9,1,
        9,9,9,9,9,9,9,9,1,
        9,9,9,9,9,9,9,9,1,
        9,9,9,9,9,9,9,9,1,
        9,9,9,9,9,9,9,9,1,
        9,9,9,9,9,9,9,9,1,
        9,9,9,9,9,9,9,9,1
    };
   
    Puzzle p = Puzzle(vec);
    

    for (auto x : p.cells[9])
        std::cout << x;

    return 0;
}

