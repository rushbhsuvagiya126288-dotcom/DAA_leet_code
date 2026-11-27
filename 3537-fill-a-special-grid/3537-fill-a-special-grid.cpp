
class Solution {
public:

    void fillGrid(vector<vector<int>>& grid,
                  int r, int c, int size, int& val) {

        // Base case: 1 x 1 grid
        if (size == 1) {
            grid[r][c] = val++;
            return;
        }

        int half = size / 2;

        // 1. Top-right quadrant
        fillGrid(grid, r, c + half, half, val);

        // 2. Bottom-right quadrant
        fillGrid(grid, r + half, c + half, half, val);

        // 3. Bottom-left quadrant
        fillGrid(grid, r + half, c, half, val);

        // 4. Top-left quadrant
        fillGrid(grid, r, c, half, val);
    }

    vector<vector<int>> specialGrid(int n) {

        int size = 1 << n;

        vector<vector<int>> grid(
            size, vector<int>(size, 0)
        );

        int val = 0;

        fillGrid(grid, 0, 0, size, val);

        return grid;
    }
};
