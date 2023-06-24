int mod=(long long)(1e9+7);
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
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