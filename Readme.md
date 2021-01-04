Program name: cgol.c
Author: Rehan Nagoor Mohideen

Description of cgol program:
The program runs Conway's game of life for a 20X40 grid where the edges are considered as borders. Takes in a file as input for the initial grid and runs the programs for the number of times (ticks) specified.

Compilation: make cgol
To run the program: ./cgol (filename) (ticks)

(filename) is replaced by the name of the file of the initial grid of size 20 X 40. name should include file type.
(ticks) is the number of processes for the game to occur. Can be left empty for 50 ticks by default.

Program name: dynCGOL.c

Description of dynCGOL program:
The program runs Conway's game of life for a dynamic grid where the edges are considered as borders. Takes in a file as input for the initial grid and runs the programs for the number of times (ticks) specified.

Compilation: make dynCGOL
To run the program: ./dynCGOL (filename) (ticks) (no. of rows) (no. of columns) 

(filename) is replaced by the name of the file of the initial grid of any size.
(ticks) is the number of processes for the game to occur.
(no. of rows) specify the number of rows of the grid in the file.
(no. of columns) specify the number of columns of the grid in the file.

Either program requires the file grid size to be as required (or inputted for second program) otherwise it will not run.

The user is only required to input 'y' or 'n' when specified or the programs may not run as intended.

