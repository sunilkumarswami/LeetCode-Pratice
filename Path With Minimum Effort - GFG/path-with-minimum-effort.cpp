//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> diff(n,vector<int> (m,1e9));
        diff[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        while(!q.empty()){
            int maxi=q.top().first,x=q.top().second.first, y=q.top().second.second;
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends