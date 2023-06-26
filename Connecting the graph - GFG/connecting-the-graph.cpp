//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> rank,par;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
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
    
    
    int findPar(int u){
        if(par[u]==u) return u;
        return par[u]=findPar(par[u]);
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& a) {
        int extraEdges=0;
        DisjointSet ds(n);
        for(auto it:a){
            int u=it[0],v=it[1];
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionByRank(u,v);
            }
            else extraEdges++;
        }
        set<int> st;
        for(int i=0;i<n;i++){
            int par=ds.findPar(i);
            st.insert(par);
        }
        int connectedComponents=st.size()-1;
        if(connectedComponents<=extraEdges) return connectedComponents;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends