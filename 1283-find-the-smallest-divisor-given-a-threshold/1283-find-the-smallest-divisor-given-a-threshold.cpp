class Solution {
public:
    int smallestDivisor(vector<int>& a, int k) {
        int n=a.size();
        int l=1,h=10e6;
        while(l<=h){
            int mid=(l+h)/2;
            int total=0;
            for(int i=0;i<n;i++){
                total+=a[i]/mid;
                if(a[i]%mid!=0) total++;
            }
            if(total<=k) h=mid-1;
            else l=mid+1;
        }
        return l;
    }
};