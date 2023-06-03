class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> edges(n, vector<int>{});
        for(int i=0; i<n; i++) {
            if(manager[i] == -1) continue;
            edges[manager[i]].push_back(i);
        }

        int ans = 0;

        queue<pair<int, int>> q;
        q.push(make_pair(headID, 0));

        while(!q.empty()) {
            int currHead = q.front().first;
            int currTime = q.front().second;
            q.pop();

            if(edges[currHead].size() == 0) {
                ans = max(ans, currTime);
                continue;
            }

            for(auto i: edges[currHead]) {
                q.push(make_pair(i, currTime+informTime[currHead]));
            }
        }

        return ans;
    }
};