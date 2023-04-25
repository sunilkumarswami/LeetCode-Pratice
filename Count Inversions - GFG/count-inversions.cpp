//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void conqure(long long low,long long mid,long long high,long long a[],long long n,long long &cnt){
        long long i=low,j=mid+1,k=0;
        long long b[high-low+2];
        while(i<=mid && j<=high){
            if(a[i]<=a[j]){
                cnt+=j-mid-1;
                b[k++]=a[i++];
            }
            else{
                b[k++]=a[j++];
            }
        }
        while(i<=mid){
            cnt+=j-mid-1;
                b[k++]=a[i++];
        }
        while(j<=high){
            b[k++]=a[j++];
        }
        k=0;
        for(int i=low;i<=high;i++)
            a[i]=b[k++];
    }
    void divide(long long low,long long high,long long a[],long long n,long long int &cnt){
        if(low>=high) return;
        long long mid=(low+high)/2;
        divide(low,mid,a,n,cnt);
        divide(mid+1,high,a,n,cnt);
        conqure(low,mid,high,a,n,cnt);
    }
    long long int inversionCount(long long a[], long long n)
    {
        long long int cnt=0;
        divide(0,n-1,a,n,cnt);
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends