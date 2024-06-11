#include "Puzzle.h"
#include "Solver.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    std::vector<int> vec = {
        4,0,0, 0,0,0, 9,3,8,
        0,3,2, 0,9,4, 1,0,0,
        0,9,5, 3,0,0, 2,4,0,

        3,7,0, 6,0,9, 0,0,4,
        5,2,9, 0,0,1, 6,7,3,
        6,0,4, 7,0,3, 0,9,0,

        9,5,7, 0,0,8, 3,0,0,
        0,0,3, 9,0,0, 4,0,0,
        2,4,0, 0,3,0, 7,0,9
    };
   
    Puzzle p = Puzzle(vec);
    Solver s = Solver{ p };
   
    
    //std::cout << 19 % 9;
    s.solve();


    return 0;
}

