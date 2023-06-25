class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> a(n,vector<int> (n,1e9));
        
        for(auto it:edges){
            a[it[0]][it[1]]=it[2];
            a[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++) a[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
                }
            }
        }
        int mini=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[i][j]<=distanceThreshold) cnt++;
            }
            if(mini>=cnt){
                mini=cnt;
                ans=i;
            }
        }
        return ans;
    }
};