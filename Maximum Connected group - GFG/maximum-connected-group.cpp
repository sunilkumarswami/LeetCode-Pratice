//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int> rank,par,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            rank[i]=0;
            par[i]=i;
        }
    }
    void unionByRank(int u,int v){
        u=findPar(u),v=findPar(v);
        if(u==v) return;
        if(rank[u]==rank[v]){
            par[v]=u;
            rank[u]++;
        }
        else if(rank[u]>rank[v]){
            par[v]=u;
        }
        else par[u]=v;
    }
    
    void unionBySize(int u,int v){
        u=findPar(u),v=findPar(v);
        if(u==v) return;
        
        if(size[u]<size[v]){
            par[u]=v;
            size[v]+=size[u];
        }else{
            par[v]=u;
            size[u]+=size[v];
        }
    }
    int findPar(int u){
        if(par[u]==u) return u;
        return par[u]=findPar(par[u]);
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        DisjointSet ds(n*m+1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int u=i*m+j;
                int dx[]={0,0,1,-1};
                int dy[]={1,-1,0,0};
                
                for(int k=0;k<4;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        int v=nx*m+ny;
                        ds.unionByRank(u,v);
                    }
                }
                }
            }
        }
        
        vector<int> cnt(n*m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int u=i*m+j;
                    cnt[ds.findPar(u)]++;
                    ans=max(ans,cnt[ds.findPar(u)]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_map<int,int> mp;
                    
                    int dx[]={0,0,1,-1};
                int dy[]={1,-1,0,0};
                int total=1;
                for(int k=0;k<4;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        int v=nx*m+ny;
                        int par=ds.findPar(v);
                        if(mp.find(par)==mp.end()){
                            mp[par]=1;
                           total+=cnt[par]; 
                        }
                    }
                }
                ans=max(ans,total);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends