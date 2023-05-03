class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int l=0,h=m-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid-1>=0 && a[i][mid-1]>a[i][mid]){
                h=mid-1;
            }
            else if(mid+1<m && a[i][mid+1]>a[i][mid]){
                l=mid+1;
            }
            else {
                // cout<<mid<<endl;
                if((i-1>=0 && a[i-1][mid]>a[i][mid]) || (i+1<n && a[i+1][mid]>a[i][mid])) l=mid+1;
                else{
                ans.push_back(i);
                ans.push_back(mid);
                return ans;
                }
            }
        }
             l=0,h=m-1;
        while(l<=h){
            int mid=(l+h)/2;
            
            if(mid+1<m && a[i][mid+1]>a[i][mid]){
                l=mid+1;
            }
            else if(mid-1>=0 && a[i][mid-1]>a[i][mid]){
                h=mid-1;
            }
            else {
                // cout<<mid<<endl;
                if((i-1>=0 && a[i-1][mid]>a[i][mid]) || (i+1<n && a[i+1][mid]>a[i][mid])) h=mid-1;
                else{
                ans.push_back(i);
                ans.push_back(mid);
                return ans;
                }
            }
        }
        }
        ans.push_back(-1);
                ans.push_back(-1);
        return ans;
    }
};