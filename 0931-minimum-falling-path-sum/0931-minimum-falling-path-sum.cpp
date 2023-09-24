class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<long long>> ds(n,vector<long long> (m,-1));
        vector<long long> last(m);
        for(int j=0;j<m;j++) last[j]=a[0][j];

        for(int i=1;i<n;i++){
            vector<long long> cur(m);
            for(int j=0;j<m;j++){
                long long left = INT_MAX,right = INT_MAX;
                if(j!=0) 
                left = a[i][j]+last[j-1];
                long long mid = a[i][j]+last[j];
                if(j<m-1)
                right = a[i][j]+last[j+1];
                cur[j] = min(left,min(right,mid));
            }
            last = cur;
        }

        long long ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,last[j]);
        }
        return ans;
    }
};