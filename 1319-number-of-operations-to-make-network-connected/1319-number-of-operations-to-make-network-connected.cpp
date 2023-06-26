class DisjointSet{
    
    public:
    vector<int> rank,par;
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
    int makeConnected(int n, vector<vector<int>>& a) {
        int extraEdges=0;
        DisjointSet ds(n);
        for(auto it:a){
            int u=it[0],v=it[1];
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionByRank(u,v);
            }
            else extraEdges++;
        }
        int connectedComponents=-1;
        for(int i=0;i<n;i++){
            if(ds.par[i]==i) connectedComponents++;
        }
        
        if(connectedComponents<=extraEdges) return connectedComponents;
        return -1;
    }
};