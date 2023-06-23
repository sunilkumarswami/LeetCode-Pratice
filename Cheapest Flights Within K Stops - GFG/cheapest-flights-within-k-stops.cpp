//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int,int>> adj[n];
        vector<int> dist(n,1e9);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0],v=flights[i][1],w=flights[i][2];
            adj[u].push_back({v,w});
        }
        
        queue<pair<int,pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,{src,0}});
        
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int node=it.second.first,cnt=it.first,money=it.second.second;
            if(cnt>k) continue;
            for(auto it:adj[node]){
                int v=it.first,w=it.second;
                if(cnt<=k && (money+w<dist[v])){
                    dist[v]=money+w;
                    pq.push({cnt+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends