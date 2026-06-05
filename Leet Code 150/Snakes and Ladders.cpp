class Solution {
public:
    pair<int,int> getPos(int num, int n) {
        int r = n - 1 - (num - 1) / n;
        int c = (num - 1) % n;

        if ((n - 1 - r) % 2 == 1) {
            c = n - 1 - c;
        }
        return {r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        vector<bool> visited(target + 1, false);
        queue<pair<int,int>> q;

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;
                if (next > target) break;

                auto [r, c] = getPos(next, n);

                if (board[r][c] != -1) {
                    next = board[r][c];
                }

                if (next == target) return moves + 1;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};
