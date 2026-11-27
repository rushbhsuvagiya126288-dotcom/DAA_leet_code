
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : freq) {
            bucket[it.second].push_back(it.first);
        }

        // Step 3: Get top K frequent elements
        vector<int> ans;

        for (int i = nums.size(); i >= 1; i--) {

            for (int num : bucket[i]) {

                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
