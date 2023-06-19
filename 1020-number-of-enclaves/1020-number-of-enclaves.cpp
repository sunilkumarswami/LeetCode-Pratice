class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),ans=0;
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
                if(mat[0][i]==1 && !vis[0][i]) {
                    vis[0][i]=1;
                    q.push({0,i});
                }
                if(mat[n-1][i]==1 && !vis[n-1][i]) {
                    vis[n-1][i]=1;
                    q.push({n-1,i});
                }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]==1 && !vis[i][0]){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(mat[i][m-1]==1 && !vis[i][m-1]){
                    vis[i][m-1]=1;
                    q.push({i,m-1});
                }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && mat[nx][ny]==1){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        } 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]==1) ans++;
            }
        }
        return ans;
    }
};