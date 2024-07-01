# Command Line Sudoku Solver
This project aims to solve the majority of sudoku puzzles using algorithms that mimmick the steps a human player would take. It is significantly more complex than creating a brute force solver, so this project will be the framework for a future GUI-based solver which will include more features such as puzzle generation and hints.  

## Methodology
The strategies used in this solver are based on Andrew Stuart's Strategies that are used in his [solver](https://www.sudokuwiki.org/Strategy_Families). I decided to start this project to challenge myself as well as practice with C++, and because Sudoku is one of my hobbies. The aim isn't to reinvent the wheel, and there are likely better or more efficient ways to code the strategies. My aim is to make a solver which can solve a breadth of sudoku puzzles logically. As such, the more advanced strategies aren't included at this time. 

The solver iterates through the strategies in the order that Stuart has them listed, which get progressively more difficult. The description of steps the solver is taking can be toggled on or off within the code. In the future I would like to make a GUI solver that can provide the solution step by step and be an aid when solving a puzzle, but at the moment the solver will complete as much of the puzzle as it can. 

## Suggestions
The solver runs in the user's default shell. I used windows powershell during development, with the launch size parameter set to 50 rows x 60 columms. If the output of the puzzle is broken, it is likely that the window needs to be wider. Pictured below is how a puzzle should look after running the program.

<p align="center">
  <img src="https://github.com/bradwinchester/sudoku-solver/assets/104231576/1ccd3bb6-3335-4da1-9541-a7086112bab9" width="500" />
</p>


