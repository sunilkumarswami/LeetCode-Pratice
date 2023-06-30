//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=1;
    void dfs(int node,int par,vector<int>adj[],vector<int> &vis,vector<int> &tim,vector<int> &low,set<int> &st){
        vis[node]=1;
        tim[node]=low[node]=timer;
        timer++;
        int child=0;
        
        for(auto it:adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,tim,low,st);
                
                low[node]=min(low[node],low[it]);
                if(low[it]>=tim[node] && par!=-1) st.insert(node);
                child++;
            }
            else low[node]=min(low[node],tim[it]);
            
        }
        if(child>1 && par==-1) st.insert(node);
    }
    
    
    void traverse(int node,vector<int> &vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) traverse(it,vis,adj);
        }
    }
    
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n,0),tim(n,0),low(n,0);
        set<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,tim,low,st);
            }
        }
        vector<int> ans(st.begin(),st.end());
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends