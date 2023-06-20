class Solution {
public:
    bool dfs(int node,int parColor,vector<vector<int>>& adj,vector<int> &vis){
        vis[node]=1-parColor;
        int m=adj[node].size();
        for(auto it:adj[node]){
            if(vis[it]==-1){
                if(!dfs(it,vis[node],adj,vis)) return false;
            }
            else if(vis[it]==vis[node]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> vis(V+1,-1);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            if(!dfs(i,1,adj,vis)) return false;
	        }
	    }
	    return true;
    }
};