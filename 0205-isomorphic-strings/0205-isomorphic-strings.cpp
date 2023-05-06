class Solution {
public:
    bool isIsomorphic(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        unordered_map<char,char> mp;
        int n=s1.size();
        map<char,bool> check;
        
        for(int i=0;i<n;i++){
            if(mp.find(s1[i])==mp.end()){
                if(check.find(s2[i])!=check.end()) return false;
                mp[s1[i]]=s2[i];
                check[s2[i]]=true;
            }
            else{
                if(mp[s1[i]]!=s2[i]) return false;
            }
        }
        return true;
    }
};