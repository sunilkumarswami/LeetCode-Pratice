class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,-1));
	    queue<pair<int,int>> q;
	    vector<vector<int>> vis(n,vector<int> (m,0));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0) {
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