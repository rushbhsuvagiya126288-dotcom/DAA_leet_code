
class Solution {
public:

    vector<int> beautifulArray(int n) {

        // Base case
        if (n == 1) {
            return {1};
        }

        // Generate smaller beautiful arrays
        vector<int> left = beautifulArray((n + 1) / 2);
        vector<int> right = beautifulArray(n / 2);

        vector<int> ans;

        // Generate odd numbers
        for (int x : left) {
            ans.push_back(2 * x - 1);
        }

        // Generate even numbers
        for (int x : right) {
            ans.push_back(2 * x);
        }

        return ans;
    }
};
