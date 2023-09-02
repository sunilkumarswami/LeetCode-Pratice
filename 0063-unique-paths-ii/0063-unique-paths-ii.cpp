class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=0,left=0;
        up=solve(i-1,j,grid,dp);
        left=solve(i,j-1,grid,dp);
        return dp[i][j]= up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0] ==1 || grid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};