class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0),ans;
        int cnt=0;
        vector<int> adj[n];
	    for(int i=0;i<pre.size();i++){
            int v=pre[i][0],u=pre[i][1];
            adj[u].push_back(v);
	        indegree[v]++;
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
	        ans.push_back(node);
	        for(auto it:adj[node]){
	           
	                indegree[it]--;
	                if(indegree[it]==0){
	                    
	                    q.push(it);
	                }
	            
	        }
	    }
	    if(ans.size()!=n) return {};
	    return ans;
    }
};