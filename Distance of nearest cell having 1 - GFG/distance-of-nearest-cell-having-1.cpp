//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,-1));
	    queue<pair<int,int>> q;
	    vector<vector<int>> vis(n,vector<int> (m,0));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1) {
	                ans[i][j]=0;
	                vis[i][j]=1;
	                q.push({i,j});
	                    }
	                }
	            }
	                
	                int cnt=0;
	                while(!q.empty()){
	                    int size=q.size();
	                    cnt++;
	                    while(size--){
	                        
	                    int x=q.front().first;
	                    int y=q.front().second;
	                    q.pop();
	                    int dx[]={0,0,1,-1};
	                    int dy[]={1,-1,0,0};
	                    for(int k=0;k<4;k++){
	                        int nx=x+dx[k];
	                        int ny=y+dy[k];
	                        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
	                            vis[nx][ny]=1;
	                            q.push({nx,ny});
	                            ans[nx][ny]=cnt;
	                        }
	                    }
	                   }
	                }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends