//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int x,int y, int lx,int ly, vector<vector<int>>& vis,vector<vector<int>> &grid,vector<pair<int,int>> &v){
        vis[x][y]=1;
        v.push_back({x-lx,y-ly});
        int n=grid.size(),m=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                dfs(nx,ny,lx,ly,vis,grid,v);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        set<vector<pair<int,int>>> store;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> v;
                    dfs(i,j,i,j,vis,grid,v);
                    
                    store.insert(v);
                }
            }
        }
        return store.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends