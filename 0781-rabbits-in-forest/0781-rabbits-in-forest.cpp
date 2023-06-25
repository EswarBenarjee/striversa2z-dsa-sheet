class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        map<int, int> s;
        for(int i=0; i<answers.size(); i++) {
            bool isAlreadyPresent = false;
            for(map<int, int>::iterator it=s.begin(); it!=s.end(); it++) {
                if(it->first == answers[i] && it->second != 0) {
                    it->second--;
                    isAlreadyPresent = true;
                    break;
                }
            }

            if(answers[i] == 0) isAlreadyPresent = false;
            if(isAlreadyPresent) continue;

            ans += answers[i]+1;
            s[answers[i]] = answers[i];
        }

        return ans;
    }
};