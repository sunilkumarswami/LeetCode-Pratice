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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        unordered_map<string,int> mp;
        int n=acc.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                string s=acc[i][j];
                if(mp.find(s)==mp.end()){
                    mp[s]=i;
                }
                else{
                    ds.unionByRank(mp[s],i);
                }
            }
        }
        
        for(auto it:mp){
            int node=it.second;
            string s=it.first;
            
            int par=ds.findPar(node);
            if(par!=node) acc[par].push_back(s);
        }
        
        set<int> st;
        for(int i=0;i<n;i++) st.insert(ds.findPar(i));
        
        vector<vector<string>> ans;
        for(auto x:st){
            auto it=acc[x];
            set<string> st2(it.begin()+1,it.end());
            
            vector<string> v;
            v.push_back(*it.begin());
            for(auto it2:st2){
                v.push_back(it2);
            }
            ans.push_back(v);
        }
        
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin()+1,ans[i].end());
        }
        return ans;
    }
};