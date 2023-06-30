//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void traverse(int node,vector<int> &vis,vector<int> adj[]){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]) traverse(it,vis,adj);
	    }
	}
	
    void dfs(int node,vector<int> &vis,vector<vector<int>>& adj, stack<int> &st){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj,st);
        }
        st.push(node);
    }
    
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i])
            dfs(i,vis,adj,st);
        }
        vector<int> adj2[n];
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adj2[it].push_back(i);
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++) vis[i]=0;
        while(!st.empty()){
            int it=st.top();
            st.pop();
            
            if(!vis[it]){
                ans++;
                traverse(it,vis,adj2);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends