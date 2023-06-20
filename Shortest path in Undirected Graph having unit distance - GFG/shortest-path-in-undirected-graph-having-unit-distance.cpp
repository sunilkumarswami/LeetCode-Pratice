//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<int> ans(n,-1),dist(n,1e9);
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            int x=edges[i][0],y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=1+dist[node];
                    q.push(it);
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends