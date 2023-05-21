class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int last=a[0][1],diff(a[0][1]-a[0][0]),ans=0;
        for(int i=1;i<a.size();i++){
            if(a[i][0]<last){
                last=min(last,a[i][1]);
                ans++;
            }
            else{
                last=a[i][1];
            }
                
        }
        return ans;
    }
};