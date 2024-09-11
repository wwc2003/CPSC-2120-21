/*
 * Name: William Cooper
 * Date Submitted: 4/15/2024
 * Lab Section: 001
 * Assignment Name: Usinig Recursion to solve the N-Queens Problem
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//global 2D array that is the board
//int board[16][16];

//function checks the diagonals
bool diagonalCheck(int **board, int n, int column, int row) {
    //variables needed for the function
    int i, j;

    //checks the row on the left side 
    for (i = 0; i < n; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    //check upper diagonal on left
    for (i = row, j = column; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    //check lower diagonal on left
    for (i = row, j = column; j >= 0 && i < n; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    //return true if nothing returned false
    return true;
}

//counts the number of solutions
int numOfSolutions(int** board, int n, int c) {
    //variables for the function
    int row;
    int count = 0;

    //if c is equal to the number of queens then return 1
    if(c == n) {
        return 1;
    }

    // for loop goes through the number of places 
    for (int i = 0; i < n; i++) {
        //sets the row to the iteration value
        row = i;

        //checks to see if queen can be placed in the board
        if (diagonalCheck(board, n, c, row)) {
            //place the queen on the board
            board[row][c] = 1;

            //recursive step
            count+=numOfSolutions(board, n, c+1);

            //backtrack
            board[row][c] = 0;
        }
    }

    //return statement
    return count;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    
    //declares the board 
    int** board = new int *[n];

    //creates the board
    for (int i = 0; i < n; i++) {
        //sets up a new board
        board[i] = new int[n];

        //second for loop
        for (int j = 0; j < n; j++) {
            //places 0 for every empty position in the board
            board[i][j] = 0;
        }
    }

    //retuns the number of solutions for n
    return numOfSolutions(board, n, 0);
        
}

// int main()
// {
//     cout << "1: " << nQueens(1) << endl;
//     cout << "2: " << nQueens(2) << endl;
//     cout << "3: " << nQueens(3) << endl;
//     cout << "4: " << nQueens(4) << endl;
//     cout << "5: " << nQueens(5) << endl;
//     cout << "6: " << nQueens(6) << endl;
//     cout << "7: " << nQueens(7) << endl;
//     cout << "8: " << nQueens(8) << endl;
//     cout << "9: " << nQueens(9) << endl;
//     cout << "10: " << nQueens(10) << endl;
//     cout << "11: " << nQueens(11) << endl;
//     cout << "12: " << nQueens(12) << endl;
//     return 0;
// }