class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        // Get all pairs
        for(auto i: nums1) {
            for(auto j: nums2) {
                pq.push( make_pair(i+j, vector<int>{i, j} ) );
                if(pq.size() > k) {
                    if( pq.top().second == vector<int>{i, j} ) {
                        pq.pop();
                        break;
                    }
                    pq.pop();
                }
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back( pq.top().second );
            pq.pop();
        }

        return ans;
    }
};