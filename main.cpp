#include "Puzzle.h"
#include "Solver.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    std::vector<int> vec = {
        8,6,3, 7,5,2, 9,4,1,
        1,9,4, 8,3,6, 7,5,2,
        2,5,7, 4,1,9, 8,6,3,

        5,7,6, 2,8,4, 3,1,9,
        9,1,2, 3,6,5, 4,7,8,
        3,4,8, 1,9,7, 5,2,6,

        7,2,9, 6,4,3, 1,8,5,
        4,8,5, 9,2,1, 6,3,7,
        6,3,1, 5,7,8, 2,9,4 
    };

    Puzzle p = Puzzle(vec);
    Solver s = Solver{ p };
   
    s.solve();


    return 0;
}

