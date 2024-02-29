#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

// Function to print the Sudoku board
void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    // Check if the number is already present in the current row, column, or 3x3 subgrid
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = 0; 
                    }
                }
                return false;  
            }
        }
    }
    //sudoku solved
    return true;  
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    cout << "Enter the Sudoku puzzle (0 for empty cells, separate numbers with spaces):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board)) {
        cout << "Sudoku puzzle solved successfully:\n";
        printBoard(board);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
