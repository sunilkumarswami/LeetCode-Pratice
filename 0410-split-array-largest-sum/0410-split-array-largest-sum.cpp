class Solution {
public:
    bool isPossible(vector<int> a,int k,int mid,int n){
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]>mid) return false;
            if(sum+a[i]>mid){
                cnt++;
                sum=a[i];
            }
            else sum+=a[i];
        }
        if(sum) cnt++;
        if(cnt<=k) return true;
        return false;
    }
    int splitArray(vector<int>& a, int k) {
        int l=INT_MAX,h=0,n=a.size();
        for(auto x:a){
            l=min(l,x);
            h+=x;
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(a,k,mid,n)) h=mid-1;
            else l=mid+1;
        }
    return l;
    }
};