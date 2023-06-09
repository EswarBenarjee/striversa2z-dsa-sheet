class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> ans(26, 0);
        for(auto i: letters) {
            ans[ (int)i - 97 ] ++;
        }

        for(int i=((int)target - 97)+1; i<26; i++)
            if( ans[i] > 0 ) return char(i)+'a';

        for(int i=0; i<((int)target - 97); i++) 
            if( ans[i] > 0 ) return char(i)+'a';

        return 'a';
    }
};