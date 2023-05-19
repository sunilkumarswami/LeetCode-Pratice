//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isPossible(int a[],int k,int mid,int n){
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
    
    int splitArray(int a[] ,int n, int k) {
        // code here
        int l=INT_MAX,h=0;
        for(int i=0;i<n;i++){
            int x=a[i];
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends