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
  
    
    // box line reduction 2
    std::vector<int> vec = {
    0,2,0, 9,4,3, 7,1,5,
    9,0,4, 0,0,0, 6,0,0,
    7,5,0, 0,0,0, 0,4,0,

    5,0,0, 4,8,0, 0,0,0,
    2,0,0, 0,0,0, 4,5,3,
    4,0,0, 3,5,2, 0,0,0,

    0,4,2, 0,0,0, 0,8,1,
    0,0,5, 0,0,4, 2,6,0,
    0,9,0, 2,0,8, 5,0,4 };

  
   
    Puzzle p = Puzzle(vec);
    
    // enable or disable descriptive output of the solver
    bool output = true; 
    //bool output = false; 

    Solver s = Solver{ p, output };
    s.solve();
   

    return 0;
}

