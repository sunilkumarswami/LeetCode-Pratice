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
    int removeStones(vector<vector<int>>& stones) {
        int nx=0,ny=0,n=stones.size();
        for(auto it:stones){
            nx=max(nx,it[0]);
            ny=max(ny,it[1]);
        }
        int totalSize=nx+ny+2;
        DisjointSet ds(totalSize);
        set<int> st;
        for(auto it:stones){
            int u=it[0],v=it[1]+nx+1;
            st.insert(u);
            st.insert(v);
            ds.unionByRank(u,v);
        }
        int ncc=0;
        for(auto i:st){
            if(ds.findPar(i)==i) ncc++;
        }
        return n-ncc;
    }
};