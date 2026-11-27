
class Solution {
public:

    Node* solve(vector<vector<int>>& grid,
                int r, int c, int size) {

        // Check whether all values are same
        int value = grid[r][c];
        bool same = true;

        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {

                if (grid[i][j] != value) {
                    same = false;
                    break;
                }
            }

            if (!same) {
                break;
            }
        }

        // If all values are same, create leaf
        if (same) {
            return new Node(value == 1, true);
        }

        // Divide grid into four parts
        int half = size / 2;

        Node* topLeft =
            solve(grid, r, c, half);

        Node* topRight =
            solve(grid, r, c + half, half);

        Node* bottomLeft =
            solve(grid, r + half, c, half);

        Node* bottomRight =
            solve(grid, r + half, c + half, half);

        // Create parent node
        return new Node(
            true,
            false,
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid) {

        int n = grid.size();

        return solve(grid, 0, 0, n);
    }
};
