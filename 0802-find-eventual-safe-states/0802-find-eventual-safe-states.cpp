class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans,indegree(n,0);
        vector<int> adj[n];
	    for(int i=0;i<n;i++){
	        for(auto it:graph[i]){
	            adj[it].push_back(i);
	            indegree[i]++;
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
	    for(int i=0;i<n;i++) if(indegree[i]==0) ans.push_back(i);
	    return ans;
    }
};