
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        // Sort numbers in descending numeric order
        sort(nums.begin(), nums.end(),
            [](const string& a, const string& b) {

                // Longer string means larger number
                if (a.size() != b.size()) {
                    return a.size() > b.size();
                }

                // Same length: compare lexicographically
                return a > b;
            }
        );

        // Return kth largest number
        return nums[k - 1];
    }
};
