//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void conqure(long long low,long long mid,long long high,vector<int> &a,long long n,long long &cnt){
        int i=low,j=mid+1,l=low,k=0;
        long long b[high-low+2];
        while(i<=mid && j<=high){
            if(a[i]<=a[j]){
                // cnt+=j-mid-1;
                b[k++]=a[i++];
            }
            else{
                while(l<=mid && a[l]<=2*a[j])
                l++;
                cnt+=mid+1-l;
                b[k++]=a[j++];
            }
        }
        while(i<=mid){
            // cnt+=j-mid-1;
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
    int countRevPairs(int n, vector<int> a) {
        // Code here
        long long int cnt=0;
        divide(0,n-1,a,n,cnt);
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends