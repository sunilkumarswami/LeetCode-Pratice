class Solution {
public:
    bool rotateString(string s1, string s2) {
        
        if(s1.size()!=s2.size()) return false;
        string s=s2+s2;
        return s.find(s1)!=string::npos;
    }
};