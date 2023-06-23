class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> diff(n,vector<int> (m,1e9));
        diff[0][0]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        while(!q.empty()){
            int maxi=q.front().first,x=q.front().second.first, y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && (max(maxi,abs(heights[nx][ny] - heights[x][y]))) < diff[nx][ny]){
                    diff[nx][ny]= max(maxi,abs(heights[nx][ny] - heights[x][y]));
                    q.push({diff[nx][ny],{nx,ny}});
                }
            }
        }
        return diff[n-1][m-1];
    }
};