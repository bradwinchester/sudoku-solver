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
       2,9,4, 5,1,3, 0,0,6,
       6,0,0, 8,4,2, 3,1,9,
       3,0,0, 6,9,7, 2,5,4,

       0,0,0, 0,5,6, 0,0,0,
       0,4,0, 0,8,0, 0,6,0,
       0,0,0, 4,7,0, 0,0,0,

       7,3,0, 1,6,4, 0,0,5,
       9,0,0, 7,3,5, 0,0,1,
       4,0,0, 9,2,8, 6,3,7 };
        
        
     
   

    Puzzle p = Puzzle(vec);
    Solver s = Solver{ p };
   
    
    s.solve();


    return 0;
}

