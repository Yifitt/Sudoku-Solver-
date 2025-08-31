#include <iostream>
#include <vector>
using namespace std;

bool is_valid_move(vector<vector<int>>&grid, int row, int col,int number) {
    for (int i = 0;i <9;i++) {
        if (grid[row][i] == number) {
            return false;
        }
    }
    for (int i = 0;i <9;i++) {
        if (grid[i][col] == number) {
            return false;
        }
    }
    int corner_row = row - row % 3;
    int corner_col = col - col % 3;

    for (int i = 0;i <3;i++) {
        for (int j = 0;j <3;j++) {
            if (grid[corner_row+i][corner_col+j] == number) {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>&grid, int row, int col) {
    if (col == 9) {
        if (row==8) {
            return true;
        }
        row++;
        col = 0;
    }
    if (grid[row][col] >0) {
        return solve(grid, row, col+1);
    }
    for (int i = 1;i <10;i++) {
        if (is_valid_move(grid,row,col,i)) {
            grid[row][col] = i;
            if (solve(grid,row,col+1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 4, 0, 7},
        {0, 0, 8, 0, 0, 0, 3, 0, 0},
        {0, 0, 1, 0, 9, 0, 0, 0, 0},
        {3, 0, 0, 4, 0, 0, 2, 0, 0},
        {0, 5, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 8, 0, 6, 0, 0, 0}
};

    if (solve(grid,0,0)) {
        for (int i = 0;i <9;i++) {
            for (int j=0;j<9;j++) {
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else {
        cout << "No solution" << '\n';
    }
    return 0;
}
