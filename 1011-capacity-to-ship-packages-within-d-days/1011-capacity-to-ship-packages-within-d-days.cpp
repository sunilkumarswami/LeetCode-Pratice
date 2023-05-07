class Solution {
public:
    int shipWithinDays(vector<int>& a, int days) {
        int n=a.size();
        // sort(a.begin(),a.end());
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,a[i]);
        }
        int l=maxi,h=maxi*n;
        while(l<=h){
            int mid=l+(h-l)/2;
            int total=0,cnt=0;
            for(int i=0;i<n;i++){
                if(total+a[i]>mid){
                    cnt++;
                    total=0;
                }
                total+=a[i];
            }
            if(total>0) cnt++;
            if(cnt>days) l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};