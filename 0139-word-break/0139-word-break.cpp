class Solution {
public:
    
    int solve(int i,string s, set<string> &st,vector<int> &dp){
        if(i>=s.size())
        {
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        string s1="";
        for(int j=i;j<s.size();j++){
            s1+=s[j];
            if(st.find(s1)!=st.end()){
                if(solve(j+1,s,st,dp)==1) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,st,dp);
    }
};