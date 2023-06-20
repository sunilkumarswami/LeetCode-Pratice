//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<int> ans(n,-1),dist(n,1e9);
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            adj[u].push_back({v,w});
        }
        
        queue<int> q;
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                int v=it.first,w=it.second;
                if(dist[node]+w<dist[v]){
                    dist[v]=w+dist[node];
                    q.push(v);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]!=1e9) ans[i]=dist[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends