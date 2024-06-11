#include "Puzzle.h"
#include "Solver.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    /*std::vector<int> vec = {
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,

        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,

        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0,
        0,0,0, 0,0,0, 0,0,0 };*/

        std::vector<int> vec = {
        4,8,0, 0,0,0, 1,0,0,
        2,7,0, 0,3,0, 0,5,0,
        0,0,0, 2,0,7, 0,0,0,

        0,0,8, 0,7,0, 3,0,0,
        0,0,0, 0,9,0, 0,2,0,
        3,0,4, 6,0,0, 0,0,0,

        0,1,0, 8,5,0, 7,0,0,
        7,4,0, 0,0,0, 0,3,0,
        0,0,0, 0,4,0, 5,6,0 };
     
   

    Puzzle p = Puzzle(vec);
    Solver s = Solver{ p };
   
    
    s.solve();


    return 0;
}

