//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> ans,indegree(n,0);
	    for(int i=0;i<n;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0)
	        {
	            q.push(i);
	            
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        for(auto it:adj[node]){
	           
	                indegree[it]--;
	                if(indegree[it]==0){
	                    
	                    q.push(it);
	                }
	            
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(indegree[i]>0) return true;
	    }
	    return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends