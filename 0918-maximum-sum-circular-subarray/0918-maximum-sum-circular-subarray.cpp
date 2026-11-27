
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int curMax = 0;
        int maxSum = nums[0];

        int curMin = 0;
        int minSum = nums[0];

        for (int num : nums) {

            // Maximum subarray (Kadane)
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            // Minimum subarray
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);

            // Calculate total sum
            total += num;
        }

        // All elements are negative
        if (maxSum < 0) {
            return maxSum;
        }

        // Compare normal and circular maximum
        return max(maxSum, total - minSum);
    }
};
