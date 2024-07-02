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
  
    
    // demanding 
    std::vector<int> vec = {
    9,1,0, 6,2,0, 3,0,0,
    0,0,0, 0,0,4, 7,0,9,
    0,7,0, 0,0,0, 0,0,0,

    7,0,4, 3,0,0, 0,0,5,
    3,0,0, 0,0,0, 0,0,0,
    0,0,0, 0,5,0, 0,2,0,

    0,0,0, 0,0,5, 0,0,0,
    0,0,5, 0,3,0, 1,0,0,
    0,8,0, 2,0,0, 0,0,0 };
    
    Puzzle p = Puzzle(vec);
    
    // enable or disable descriptive output of the solver
    bool output = true; 
    //bool output = false; 

    Solver s = Solver{ p, output };
    s.solve();
   

    return 0;
}

