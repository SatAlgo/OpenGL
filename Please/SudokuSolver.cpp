#include <iostream>
using namespace std;

bool isSafe(int grid[4][4], int row, int col, int num) {
    // Check if 'num' is in the current row or column
    for (int i = 0; i < 4; i++) {
        if (grid[row][i] == num || grid[i][col] == num) return false;
    }

    // Check if 'num' is in the 2x2 subgrid
    int startRow = row - row % 2, startCol = col - col % 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[4][4]) {
    int row = -1, col = -1;
    bool empty = false;

    // Find an empty cell (represented by 0)
    for (int i = 0; i < 4 && !empty; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                empty = true;
                break;
            }
        }
    }

    // If no empty cell is found, puzzle is solved
    if (!empty) return true;

    // Try placing numbers 1 to 4 in the empty cell
    for (int num = 1; num <= 4; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively attempt to solve the rest of the grid
            if (solveSudoku(grid)) return true;

            // Backtrack if placing 'num' doesn't lead to a solution
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[4][4];

    cout << "Enter the Sudoku grid (use 0 for empty cells):" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cout<<"Puzzle Sudoku: "<<endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout<<endl; 
    }

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}


// 1 2 3 4 
// 4 3 2 1 
// 3 4 1 2 
// 2 1 4 3 
