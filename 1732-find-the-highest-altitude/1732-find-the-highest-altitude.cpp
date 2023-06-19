class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, highest = 0;
        for(auto i: gain) {
            alt += i;
            if(alt > highest) highest = alt;
        }
        return highest > 0 ? highest : 0;
    }
};