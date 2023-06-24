//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod (int)(1e9+7)
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            long long distance=pq.top().first,node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                long long v=it.first,w=it.second;

                if(distance+w<dist[v]){
                    ways[v]=ways[node];
                    dist[v]=distance+w;
                    pq.push({dist[v],v});
                }
                else if((distance+w)==dist[v]){
                    ways[v]=(ways[v]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends