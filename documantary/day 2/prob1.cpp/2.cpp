/*Q2: Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition. Each column must contain the digits 1-9 without repetition.Each of the nine
 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition. Note:A Sudoku board (partially filled) could be valid but is
  not necessarily solvable. Only the filled cells need to be validated according to the mentioned rules.*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create sets to track seen numbers
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.') { // Only check filled cells
                    // Calculate the index for the 3x3 box
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    
                    // Check if the number is already seen in the current row, column, or box
                    if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                        return false; // Invalid if we see the number again
                    }
                    
                    // Add the number to the respective sets
                    rows[i].insert(num);
                    cols[j].insert(num);
                    boxes[boxIndex].insert(num);
                }
            }
        }
        return true; // If no conflicts were found, the board is valid
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solution.isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}