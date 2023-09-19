class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<long long>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>> dp(n,vector<long long> (m,-1));
        dp[0][0]=grid[0][0];
        int sum=grid[0][0];
        for(int i=1;i<n;i++){
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        sum=grid[0][0];
        for(int j=1;j<m;j++){
            sum+=grid[0][j];
            dp[0][j]=sum;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]); 
            }
        }
        return dp[n-1][m-1];
    }
};