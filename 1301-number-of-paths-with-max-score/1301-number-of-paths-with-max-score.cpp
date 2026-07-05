class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        // score[i][j] = maximum score from (i,j) to S
        vector<vector<int>> score(n, vector<int>(n, -1));

        // ways[i][j] = number of paths achieving score[i][j]
        vector<vector<long long>> ways(n, vector<long long>(n, 0));

        // Base case: Start cell (S)
        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        // Fill from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X')
                    continue;

                // Skip S because it is already initialized
                if (i == n - 1 && j == n - 1)
                    continue;

                int bestScore = -1;
                long long totalWays = 0;

                // Down
                if (i + 1 < n && score[i + 1][j] != -1) {

                    if (score[i + 1][j] > bestScore) {
                        bestScore = score[i + 1][j];
                        totalWays = ways[i + 1][j];
                    }
                    else if (score[i + 1][j] == bestScore) {
                        totalWays = (totalWays + ways[i + 1][j]) % MOD;
                    }
                }

                // Right
                if (j + 1 < n && score[i][j + 1] != -1) {

                    if (score[i][j + 1] > bestScore) {
                        bestScore = score[i][j + 1];
                        totalWays = ways[i][j + 1];
                    }
                    else if (score[i][j + 1] == bestScore) {
                        totalWays = (totalWays + ways[i][j + 1]) % MOD;
                    }
                }

                // Diagonal
                if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] != -1) {

                    if (score[i + 1][j + 1] > bestScore) {
                        bestScore = score[i + 1][j + 1];
                        totalWays = ways[i + 1][j + 1];
                    }
                    else if (score[i + 1][j + 1] == bestScore) {
                        totalWays = (totalWays + ways[i + 1][j + 1]) % MOD;
                    }
                }

                // No valid path
                if (bestScore == -1)
                    continue;

                int value = 0;

                if (board[i][j] >= '0' && board[i][j] <= '9')
                    value = board[i][j] - '0';

                score[i][j] = bestScore + value;
                ways[i][j] = totalWays % MOD;
            }
        }

        if (ways[0][0] == 0)
            return {0, 0};

        return {score[0][0], (int)ways[0][0]};
    }
};