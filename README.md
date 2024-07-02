# Command Line Sudoku Solver
This project aims to solve the majority of sudoku puzzles using algorithms that mimmick the steps a human player would take. It is significantly more complex than creating a brute force solver, so this project will be the framework for a future GUI-based solver which will include more features such as puzzle generation and hints.  

## Methodology
The strategies used in this solver are based on Andrew Stuart's Strategies that are used in his [solver](https://www.sudokuwiki.org/Strategy_Families). I decided to start this project to challenge myself as well as practice with C++, and because Sudoku is one of my hobbies. The aim isn't to reinvent the wheel, and there are likely better or more efficient ways to code the strategies. My aim is to make a solver which can solve a breadth of sudoku puzzles logically. As such, the more advanced strategies aren't included at this time. In the future I would like to make a GUI solver that can provide the solution step by step and be an aid when solving a puzzle, but at the moment the solver will complete as much of the puzzle as it can. I chose to store possibilities as ints instead of a string or bitset, primarily because it was simpler to think about numbers as numbers. Upon entering a puzzle, each cell is filled with either a user-defined number 1-9 or as a 0. When the puzzle is generated all cells are converted into arrays (vector) holding either the preset number or all numbers 1-9, representing the possible numbers that cell could contain. These arrays are stored in a dictionary for easy access to any cell, with a the key being numbers 1 to 81. 

The solver iterates through the strategies in the order that Stuart has them listed, which get progressively more difficult. A description of steps the solver is taking can be toggled on or off within the code. The solver will run through each strategy iteratively, until the puzzle is solved or until a preset number of iterations has been met to prevent an infinite loop if a solution cannot be found. Currently, the solver has the basic strategies implemented, as listed below. I've found that these are able to solve most demanding puzzles from my current Sudoku book. I may implement more advanced strategies in the future, but for now I want to move onto other projects. 

Current Strategies: 
- Naked Pairs
- Naked Triples
- Hidden Pairs
- Hidden Triples
- Pointing Pairs
- Box / Line reduction

You can learn more about these strategies in the link above. I decided not to include the quad variety of naked and hidden sets since they seem to be rare enough that it not needed to solve a majority of puzzles. 

## Suggestions
The solver runs in the user's default shell. I used windows powershell during development, with the launch size parameter set to 50 rows x 60 columms. If the output of the puzzle is broken, it is likely that the window needs to be wider. Pictured below is how a puzzle should look after running the program.

<p align="center">
  <img src="https://github.com/bradwinchester/sudoku-solver/assets/104231576/1ccd3bb6-3335-4da1-9541-a7086112bab9" width="500" />
</p>


