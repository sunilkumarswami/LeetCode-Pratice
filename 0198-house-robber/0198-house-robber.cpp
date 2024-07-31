class Solution {
public:
    int fun(int ind,vector<int> &a,vector<int> &dp){
        if(ind==0) return a[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=a[ind]+fun(ind-2,a,dp);
        int nonpick=fun(ind-1,a,dp);
        return dp[ind]=max(pick,nonpick);
    }
    int rob(vector<int>& a) {
        int n=a.size(),ans=0;
        vector<int> dp(n,-1);
        int sec=a[0],fir;
        if(n==1) return sec;
            fir=max(sec,a[1]);
        
        for(int i=2;i<n;i++){
            int cur=max(fir,a[i]+sec);
            sec=fir;
            fir=cur;
        }
        return fir;
    }
};