class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    long long total = 0;


    for (auto &row : grid)
        for (int x : row)
            total += x;

    if (total % 2 != 0) return false;

    long long prefix = 0;

    for (int i = 0; i < n - 1; i++) {
        long long rowSum = 0;
        for (int j = 0; j < m; j++) {
            rowSum += grid[i][j];
        }
        prefix += rowSum;

        if (prefix == total - prefix) return true;
    }


    prefix = 0;
    for (int j = 0; j < m - 1; j++) {
        long long colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += grid[i][j];
        }
        prefix += colSum;

        if (prefix == total - prefix) return true;
    }

    return false;

    }
};