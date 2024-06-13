#include "Puzzle.h"
#include "Solver.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    // empty vector for testing
    /*
    std::vector<int> vec = {
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,

        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,

        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0 };
        */
       
    std::vector<int> vec = {
    7,2,0, 4,0,8, 0,3,0,
    0,8,0, 0,0,0, 0,4,7,
    4,0,1, 0,7,6, 8,0,2,

    8,1,0, 7,3,9, 0,0,0,
    0,0,0, 8,5,1, 0,0,0,
    0,0,0, 2,6,4, 0,8,0,

    2,0,9, 6,8,0, 4,1,3,
    3,4,0, 0,0,0, 0,0,8,
    1,6,8, 9,4,3, 2,7,5 };
    
    Puzzle p = Puzzle(vec);
    Solver s = Solver{ p };
   
    

    s.solve();


    return 0;
}

