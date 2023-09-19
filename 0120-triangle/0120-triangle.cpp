class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& tri,vector<vector<int>> &dp){
        int n=tri.size(),m=tri[i].size();
        if(i==n-1) return tri[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = tri[i][j]+min(solve(i+1,j,tri,dp),solve(i+1,j+1,tri,dp));
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            vector<int> temp(tri[i].size(),-1);
            dp.push_back(temp);
        }
        
        for(int j=0;j<tri[n-1].size();j++){
            dp[n-1][j]=tri[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<tri[i].size();j++){
                dp[i][j] = tri[i][j] +min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};