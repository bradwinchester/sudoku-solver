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
  
    
    // box line reduction
    std::vector<int> vec = {
    0,1,6, 0,0,7, 8,0,3,
    0,9,0, 8,0,0, 0,0,0,
    8,7,0, 0,0,1, 0,6,0,

    0,4,8, 0,0,0, 3,0,0,
    6,5,0, 0,0,9, 0,8,2,
    0,3,9, 0,0,0, 6,5,0,

    0,6,0, 9,0,0, 0,2,0,
    0,8,0, 0,0,2, 9,3,6,
    9,2,4, 6,0,0, 5,1,0 };

  
   
    Puzzle p = Puzzle(vec);
    
    // enable or disable descriptive output of the solver
    bool output = true; 
    //bool output = false; 

    Solver s = Solver{ p, output };
    s.solve();
   

    return 0;
}

