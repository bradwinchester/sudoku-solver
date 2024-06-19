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

    // hidden triples
    std::vector<int> vec = {
    0,0,0, 0,0,1, 0,3,0,
    2,3,1, 0,9,0, 0,0,0,
    0,6,5, 0,0,3, 1,0,0,

    6,7,8, 9,2,4, 3,0,0,
    1,0,3, 0,5,0, 0,0,6,
    0,0,0, 1,3,6, 7,0,0,

    0,0,9, 3,6,0, 5,7,0,
    0,0,6, 0,1,9, 8,4,3,
    3,0,0, 0,0,0, 0,0,0 };
    
   
    Puzzle p = Puzzle(vec);
    Solver s = Solver{ p };
   
    s.solve();
   

    return 0;
}

