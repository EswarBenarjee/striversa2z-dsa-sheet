class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(int i=0; i<s.size(); i++) {
            if(isupper(s[i])) s1 += s[i]+32;
            else if(isalnum(s[i])) s1 += s[i];
        }

        for(int i=0; i<s1.size()/2; i++) {
            if(s1[i] != s1[s1.size()-1-i]) return false;
        }
        return true;
    }
};