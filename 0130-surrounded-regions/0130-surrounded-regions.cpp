class Solution {
public:
    void dfs(int x,int y,int n, int m, vector<vector<char>>mat,vector<vector<int>>& vis){
        vis[x][y]=1;
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && mat[nx][ny]=='O'){
                dfs(nx,ny,n,m,mat,vis);
            }
        } 
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<m;i++){
                if(mat[0][i]=='O' && !vis[0][i]) dfs(0,i,n,m,mat,vis);
                if(mat[n-1][i]=='O' && !vis[n-1][i]) dfs(n-1,i,n,m,mat,vis);
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]) dfs(i,0,n,m,mat,vis);
                if(mat[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,n,m,mat,vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]) mat[i][j]='X';
            }
        }
    }
};