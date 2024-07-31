class Solution {
public:
    int fun(int ind,vector<int> &a,vector<int> &dp){
        int n=a.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int val=0;
        for(int i=ind+2;i<n;i++){
            val=max(val,a[i]+fun(i,a,dp));
        }
        return dp[ind]=val;
    }
    int rob(vector<int>& a) {
        int n=a.size(),ans=0;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,a[i]+fun(i,a,dp));
        }
        return ans;
    }
};