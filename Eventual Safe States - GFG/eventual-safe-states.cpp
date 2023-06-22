//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool cycle(int node,vector<int> &vis,vector<int> &pathVis,vector<int> adj[],vector<int> &check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]) {if(cycle(it,vis,pathVis,adj,check)) {
                check[node]=0;
                return true;
                
            }}
            else if(pathVis[it]){ 
                check[node]=0;
                return true;
                
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(n,0),pathVis(n,0),check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            bool b=cycle(i,vis,pathVis,adj,check);
        }
        for(int i=0;i<n;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends