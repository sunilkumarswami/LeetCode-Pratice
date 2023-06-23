class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
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