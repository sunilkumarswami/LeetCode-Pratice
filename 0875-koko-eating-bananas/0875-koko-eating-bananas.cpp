class Solution {
public:
    int minEatingSpeed(vector<int>& a, int H) {
        int n=a.size();
         int l=1,h=1e9;
        for(int i=0;i<n;i++){
            l=min(l,a[i]);
            h=max(h,a[i]);
        }
    
        while(l<=h){
            int mid=(l+h)/2;
            long long total=0;
            for(int i=0;i<n;i++){
                total+=a[i]/mid;
                if(a[i]%mid!=0) total++;
            }
            if(H>=total) h=mid-1;
            else l=mid+1;
        }
        return l;
    }
};