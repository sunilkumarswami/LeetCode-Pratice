class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        dist[0][0]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        
        while(!pq.empty()){
            int dis=pq.top().first,x=pq.top().second.first,y=pq.top().second.second;
            pq.pop();
            int dx[]={0,0,-1,1,-1,1,-1,1};
            int dy[]={1,-1,0,0,-1,1,1,-1};
            
            for(int i=0;i<8;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && (dis+1<dist[nx][ny])){
                    dist[nx][ny]=1+dis;
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];
    }
};