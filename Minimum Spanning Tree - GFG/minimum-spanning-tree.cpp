//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
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
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int sum=0;
        DisjointSet ds(n);
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],i,it[0]});
            }
        }
        sort(edges.begin(),edges.end());
        
        for(auto it:edges){
            int w=it[0],u=it[1],v=it[2];
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionByRank(u,v);
                sum+=w;
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends