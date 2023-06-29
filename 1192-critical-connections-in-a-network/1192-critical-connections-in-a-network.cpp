class Solution {
public:
    void dfs(int node,int par, vector<int> adj[], int &cnt,vector<int> &timee,vector<int> &low,vector<int> &vis,vector<vector<int>> &ans){
        vis[node]=1;
        timee[node]=low[node]=cnt;
        cnt++;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(it,node,adj,cnt,timee,low,vis,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>timee[node]) ans.push_back({node,it});
                
            }
            else low[node]=min(low[node],low[it]);
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> timee(n,0),low(n,0),vis(n,0);
        int cnt=1;
        for(int i=0;i<n;i++){
            if(!vis[i]) {dfs(i,-1,adj,cnt,timee,low,vis,ans);}
        }
        return ans;
    }
};