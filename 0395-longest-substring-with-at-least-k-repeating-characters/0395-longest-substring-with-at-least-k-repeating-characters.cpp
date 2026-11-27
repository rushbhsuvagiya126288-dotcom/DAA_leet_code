
class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.length();
        int ans = 0;

        // Try 1 to 26 unique characters
        for (int target = 1; target <= 26; target++) {

            vector<int> freq(26, 0);

            int left = 0;
            int uniqueCount = 0;
            int countAtLeastK = 0;

            for (int right = 0; right < n; right++) {

                int index = s[right] - 'a';

                if (freq[index] == 0) {
                    uniqueCount++;
                }

                freq[index]++;

                if (freq[index] == k) {
                    countAtLeastK++;
                }

                // Shrink window if unique characters exceed target
                while (uniqueCount > target) {

                    int leftIndex = s[left] - 'a';

                    if (freq[leftIndex] == k) {
                        countAtLeastK--;
                    }

                    freq[leftIndex]--;

                    if (freq[leftIndex] == 0) {
                        uniqueCount--;
                    }

                    left++;
                }

                // Check whether current window is valid
                if (uniqueCount == target &&
                    countAtLeastK == target) {

                    ans = max(ans, right - left + 1);
                }
            }
        }

        return ans;
    }
};
