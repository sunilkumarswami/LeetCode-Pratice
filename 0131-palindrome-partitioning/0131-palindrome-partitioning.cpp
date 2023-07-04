class Solution {
public:
    bool isPelindrome(string s){
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(int ind,string s,vector<string> &ds,vector<vector<string>> &ans){
        int n=s.size();
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<n;i++){
            string st=s.substr(ind,i-ind+1);
            if(isPelindrome(st)){
                ds.push_back(st);
                solve(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,s,ds,ans);
        return ans;
    }
};