//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int> a[], int V,vector<int> &vis){
        if(vis[node]) return;
        vis[node]=1;
        for(int v:a[node]){
            if(!vis[v]){
                dfs(v,a,V,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V+1,0);
        int cnt=0;
        vector<int> a[V];
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(adj[u][v]==1 && u!=v)
                a[u].push_back(v);
            }
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,a,V,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends