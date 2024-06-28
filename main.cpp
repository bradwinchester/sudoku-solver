#include "Puzzle.h"
#include "Solver.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>


int main()
{
    /* empty vector for testing
    
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


    // intersection removal
    std::vector<int> vec = {
    0,1,7, 9,0,3, 6,0,0,
    0,0,0, 0,8,0, 0,0,0,
    9,0,0, 0,0,0, 5,0,7,

    0,7,2, 0,1,0, 4,3,0,
    0,0,0, 4,0,2, 0,7,0,
    0,6,4, 3,7,0, 2,5,0,

    7,0,1, 0,0,0, 0,6,5,
    0,0,0, 0,3,0, 0,0,0,
    0,0,5, 6,0,1, 7,2,0 };
    
   
    Puzzle p = Puzzle(vec);
    
    // enable or disable descriptive output of the solver
    bool output = true; 

    Solver s = Solver{ p, output };
    s.solve();
   

    return 0;
}

