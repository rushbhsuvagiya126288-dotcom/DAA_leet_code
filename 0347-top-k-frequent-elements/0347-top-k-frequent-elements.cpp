class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for (int x : nums)
            mp[x]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto x : mp)
            bucket[x.second].push_back(x.first);

        vector<int> ans;

        for (int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            for (int x : bucket[i]) {
                ans.push_back(x);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};