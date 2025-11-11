The program revolves around Conway’s Game of Life (more information here: https://site-pa.netlify.app/proiecte/game_of_life/
).
It is divided into 4 main tasks and one bonus subtask:

Task 1:
Implement the rules of the Game of Life based on a given number K of generations.

Task 2:
According to the Game of Life rules, store in a stack of lists the addresses (indices i and j) of the cells that change their state.

Task 2 – Bonus:
The reverse of Task 2:
Based on the stack that contains the positions of the cells that changed their state, reconstruct the initial matrix.

Task 3:
Create a perfect binary tree of height K (where K is the number of given generations).
Each node stores the current generation of the matrix after applying the rules.
A new rule (Rule B) is introduced:

Any cell with exactly 2 live neighbors becomes alive.

At each node:

The left child applies Rule B,
The right child applies Rule A (the standard rule).

File Structure:

game_of_life.c – contains the main function.

functions.c – contains the main functions used in Tasks 1, 2, and 3.

stive_liste.c – contains functions used for Task 2.

stive_liste.h – contains the structures used in Task 2.

bonus.c and bonus.h – used exclusively for the Task 2 Bonus.

Main Functions Used:

aplicare_reguli() – modifies a matrix using Rule A (standard Game of Life rule).

aplicare_reguli2() – modifies a matrix using Rule B (introduced in Task 3).

generatie_matrice() – creates a matrix that stores, for each position, the number of live neighbors.

numar_vecini() – calculates how many live cells surround the current cell.

Execution:

To run the program, install the checker along with InputData and RefData (used for verification).
