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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> a(n,vector<int> (m,0));
        DisjointSet ds(n*m+1);
        int cnt=0;
        vector<int> ans;
        for(auto it:operators){
            int i=it[0],j=it[1];
            if(a[i][j]==0){
                cnt++;
                a[i][j]=1;
                int u=i*m+j;
                int dx[]={0,0,1,-1};
                int dy[]={1,-1,0,0};
                
                for(int k=0;k<4;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && a[nx][ny]==1){
                        int v=nx*m+ny;
                        if(ds.findPar(u)!=ds.findPar(v)){
                            cnt--;
                            ds.unionByRank(u,v);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends