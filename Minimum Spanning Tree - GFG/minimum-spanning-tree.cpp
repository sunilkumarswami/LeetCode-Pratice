//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int sum=0;
        // vector<pair<int,int>> adj[n];
        // for(auto it:edges){
        //     adj[it[0]].push_back({it[1],it[2]});
        //     adj[it[1]].push_back({it[0],it[2]});
        // }
        // for(int i=0;i<edges.size();i++){
        //     adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        //     adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        // }
        vector<int> vis(n,0);
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,-1}});
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first,node=it.second.first,par=it.second.second;
            
            if(!vis[node]){
                vis[node]=1;
                sum+=wt;
                
                for(auto it:adj[node]){
                    int v=it[0],w=it[1];
                    if(!vis[v]){
                        pq.push({w,{v,node}});
                    }
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends