//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> dest) {
        int n=grid.size(),m=grid[0].size();
        if(grid[s.first][s.second]==0 || grid[dest.first][dest.second]==0) return -1;
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[s.first][s.second]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{s.first,s.second}});
        
        while(!q.empty()){
            int dis=q.front().first,x=q.front().second.first,y=q.front().second.second;
            q.pop();
            int dx[]={-1, 0, 1, 0};
            int dy[]={0, 1, 0, -1};
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && (dis+1<dist[nx][ny])){
                    dist[nx][ny]=1+dis;
                    if(dest.first==nx && dest.second==ny) return 1+dis;
                    q.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        if(dist[dest.first][dest.second]==1e9) return -1;
        return dist[dest.first][dest.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends