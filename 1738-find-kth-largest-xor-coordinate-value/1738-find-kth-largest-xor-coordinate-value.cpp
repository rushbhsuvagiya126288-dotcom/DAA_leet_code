
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));

        vector<int> values;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int up = (i > 0) ? prefix[i - 1][j] : 0;

                int left = (j > 0) ? prefix[i][j - 1] : 0;

                int diagonal = (i > 0 && j > 0)
                    ? prefix[i - 1][j - 1] : 0;

                prefix[i][j] = matrix[i][j]
                               ^ up
                               ^ left
                               ^ diagonal;

                values.push_back(prefix[i][j]);
            }
        }

        // Sort in descending order
        sort(values.rbegin(), values.rend());

        return values[k - 1];
    }
};
