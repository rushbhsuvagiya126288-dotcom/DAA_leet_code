
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max Heap: {distance, {x, y}}
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto &p : points) {

            int x = p[0];
            int y = p[1];

            // Calculate squared distance
            int dist = x * x + y * y;

            // Insert into heap
            pq.push({dist, {x, y}});

            // Keep heap size equal to k
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Store answer
        vector<vector<int>> ans;

        while (!pq.empty()) {

            auto point = pq.top();
            pq.pop();

            ans.push_back({
                point.second.first,
                point.second.second
            });
        }

        return ans;
    }
};
