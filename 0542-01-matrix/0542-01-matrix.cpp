class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> visited(m, vector<int>(n, -1));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!mat[i][j]) q.push(make_pair(make_pair(i, j), 0));
            }
        }

        while(!q.empty()) {
            int s = q.size();
            for(int k=0; k<s; k++) {
                int i = q.front().first.first;
                int j = q.front().first.second;
                int value = q.front().second;
                q.pop();

                if(i<0 || j<0 || i>=m || j>=n || visited[i][j]!=-1) continue;

                visited[i][j] = value;
                q.push(make_pair(make_pair(i-1, j), value+1));
                q.push(make_pair(make_pair(i+1, j), value+1));
                q.push(make_pair(make_pair(i, j-1), value+1));
                q.push(make_pair(make_pair(i, j+1), value+1));
            }
        }

        return visited;
    }
};