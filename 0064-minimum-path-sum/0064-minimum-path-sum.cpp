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
        vector<int> last(m,0);
        
        last[0]=grid[0][0];
        int sum=grid[0][0];
        
        sum=grid[0][0];
        for(int j=1;j<m;j++){
            sum+=grid[0][j];
            last[j]=sum;
        }
        
        for(int i=1;i<n;i++){
            vector<int> cur(m,0);
            cur[0]=last[0]+grid[i][0];
            for(int j=1;j<m;j++){
                cur[j]=grid[i][j]+min(last[j],cur[j-1]); 
            }
            last=cur;
        }
        return last[m-1];
    }
};