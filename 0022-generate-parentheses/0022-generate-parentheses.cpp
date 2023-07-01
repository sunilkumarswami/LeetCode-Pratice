class Solution {
public:
    void solve(string s,int open,int close,int n,vector<string> &ans){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open == close){
            s+='(';
            solve(s,open+1,close,n,ans);
        }
        else{
            if(open<n){
                string s1=s+'(';
                solve(s1,open+1,close,n,ans);
            }
            s+=')';
            solve(s,open,close+1,n,ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
       string s="(";
       
       solve(s,1,0,n,ans);
       return ans;
    }
};