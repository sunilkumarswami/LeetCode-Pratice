class Solution {
public:
    int total=0;
    void conqure(long long low,long long mid,long long high,vector<int> &a,long long n,long long &cnt){
        int i=low,j=mid+1;
        for(i=low;i<=mid;i++){
            while(j<=high && a[i]>(long long)2*a[j]){
                j++;
            }
            cnt+=j-(mid+1);
        }
         i=low,j=mid+1;
        long long k=0;
        long long b[high-low+2];
        while(i<=mid && j<=high){
            if(a[i]<=a[j]){
                b[k++]=a[i++];
            }
            else{
                b[k++]=a[j++];
            }
        }
        while(i<=mid){
                b[k++]=a[i++];
        }
        while(j<=high){
            b[k++]=a[j++];
        }
        k=0;
        for(int i=low;i<=high;i++)
            a[i]=b[k++];
    }
    void divide(long long low,long long high,vector<int> &a,long long n,long long int &cnt){
        if(low>=high) return;
        long long mid=(low+high)/2;
        divide(low,mid,a,n,cnt);
        divide(mid+1,high,a,n,cnt);
        conqure(low,mid,high,a,n,cnt);
    }
    int reversePairs(vector<int>& a) {
        long long int cnt=0,n=a.size();
        divide(0,n-1,a,n,cnt);
        return cnt;
    }
};