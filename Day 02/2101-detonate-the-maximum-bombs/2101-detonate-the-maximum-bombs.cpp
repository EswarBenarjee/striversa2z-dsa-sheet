class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<bool>&visited,int &count,int i)
    {
        visited[i] = true;
        count++;
        for(auto j:graph[i])
            if(!visited[j]) dfs(graph,visited,count,j); 
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++)
        {
            long long x1,y1,r1;
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long x,y;
                    x = abs(x1-bombs[j][0]);
                    y = abs(y1-bombs[j][1]);
                    if(x*x+y*y<=r1*r1) graph[i].push_back(j);
                }
            }
        }
        int bomb = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int count=0;
            vector<bool>visited(n,false);
            dfs(graph,visited,count,i);
            bomb = max(count,bomb);
        }
        return bomb; 
    }
};