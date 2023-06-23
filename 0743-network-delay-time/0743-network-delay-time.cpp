class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty()){
            int distance=pq.top().first,node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int v=it.first,w=it.second;
                if(distance+w<dist[v]){
                    dist[v]=distance+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int it=dist[i];
            if(it==1e9) return -1;
            ans=max(ans,it);
        }
    return ans;
    }
};