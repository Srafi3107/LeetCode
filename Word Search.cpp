class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        if (index == word.size())
            return true;

        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != word[index])
            return false;

        char temp = board[r][c];
        board[r][c] = '#'; // Mark as visited

        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        board[r][c] = temp; // Restore the cell

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};
