class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        
        // Check the row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;

            if (board[i][col] == num)
                return false;
        }

        // Find the starting position of the 3 × 3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        // Check the 3 × 3 box
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        
        // Find an empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    // Try numbers from 1 to 9
                    for (char num = '1'; num <= '9'; num++) {

                        if (isValid(board, row, col, num)) {

                            // Place the number
                            board[row][col] = num;

                            // Solve the remaining board
                            if (solve(board))
                                return true;

                            // Backtrack: remove the number
                            board[row][col] = '.';
                        }
                    }

                    // No valid number can be placed here
                    return false;
                }
            }
        }

        // No empty cells remain, so Sudoku is solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
