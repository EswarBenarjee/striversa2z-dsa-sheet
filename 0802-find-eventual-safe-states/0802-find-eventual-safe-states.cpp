class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // creating adjacency list and inDegree vector
        int n = graph.size();
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                inDegree[i]++;
            }
        }

        // checking nodes which have inDegree zero and then inserting it in queue
        queue<int> que;
        for(int i=0; i<n; i++){
            if(!inDegree[i]) que.push(i);
        }

        // topo sort
        vector<int> safeNodes;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            safeNodes.push_back(node);

            for(auto it: adj[node]){
                inDegree[it]--;
                if(!inDegree[it]) que.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};