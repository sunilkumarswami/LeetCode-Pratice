class Solution {
public:
    void solve(int ind,string &dig,unordered_map<char,string> &mp,string &str,vector<string> &ans){
        if(ind==dig.size()){
            ans.push_back(str);
            return;
        }
        string s= mp[dig[ind]];
        // cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            str.push_back(s[i]);
            solve(ind+1,dig,mp,str,ans);
            str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string str="";
        vector<string>  ans;
        if(digits.size()==0) return ans;
        solve(0,digits,mp,str,ans);
        return ans;
    }
};