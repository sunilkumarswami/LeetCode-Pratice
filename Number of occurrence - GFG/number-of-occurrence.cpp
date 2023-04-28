//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int a[], int n, int x) {
	    int l=0,r=n-1,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x){
            ans=mid;
            r=mid-1;
        }
        else if(a[mid]>x){
            r=mid-1;
        }
        else 
            l=mid+1;
    }
    if(ans==-1) return 0;
    int left=ans;
    ans=-1;
    l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x){
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]<x){
            l=mid+1;
        }
        else 
            r=mid-1;
    }
    if(ans==-1) return 0;
    return ans-left+1;
	}
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends