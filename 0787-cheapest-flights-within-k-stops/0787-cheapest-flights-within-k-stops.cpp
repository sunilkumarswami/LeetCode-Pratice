class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int S, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0],v=flights[i][1],wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n,INT_MAX),par(n);
        //priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++) par[i]=i;
        
        dist[S]=0;
        par[S]=S;
        pq.push({0,S});
        
        int cnt=k+1;
        while(!pq.empty()){
            int size=pq.size();
            if(cnt==0) break;
            cnt--;
            while(size--){
                
                int dis=pq.front().first;
                int u=pq.front().second;
                pq.pop();
            //if(dist[u]<dis) continue;
                for(auto it:adj[u]){
                int v=it.first,wt=it.second;
                if(dis+wt<dist[v]){
                    dist[v]=dis+wt;
                    par[v]=u;
                    pq.push({dist[v],v});
                }
            }
            }
            
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};