#include <iostream>
#include <vector>
#include <utility> // For std::pair

using namespace std;

const int SIZE = 9;

// Function to check if a number can be placed in the specified row and column
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to find an empty location in the Sudoku board
pair<int, int> findEmptyLocation(const vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return {i, j};  // Return row and column of the empty cell
            }
        }
    }
    return {-1, -1};  // Return an invalid position if no empty cell is found
}

// Backtracking function to solve the Sudoku
bool solveSudoku(vector<vector<int>>& board) {
    pair<int, int> empty = findEmptyLocation(board);
    int row = empty.first;
    int col = empty.second;

    if (row == -1) {
        return true;  // Puzzle solved
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0;  // Reset on backtrack
        }
    }

    return false;  // No solution
}

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 1, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku Board:\n";
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku Board:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
