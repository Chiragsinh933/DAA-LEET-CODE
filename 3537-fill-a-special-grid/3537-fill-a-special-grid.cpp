class Solution {
public:
    void solve(vector<vector<int>>& grid, int r, int c,
               int size, int start) {

        if (size == 1) {
            grid[r][c] = start;
            return;
        }

        int half = size / 2;
        int block = half * half;

        solve(grid, r, c + half, half, start);

        solve(grid, r + half, c + half, half, start + block);

        solve(grid, r + half, c, half, start + 2 * block);

        solve(grid, r, c, half, start + 3 * block);
    }

    vector<vector<int>> specialGrid(int n) {

        int size = 1 << n;

        vector<vector<int>> grid(size, vector<int>(size));

        solve(grid, 0, 0, size, 0);

        return grid;
    }
};