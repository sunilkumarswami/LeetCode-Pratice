//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int a[], int n) {
	    // code here
	    int l=0,h=n-1,mini=INT_MAX;
	    if(a[n-1]>=a[0]) return 0;
	    while(l<=h){
	        int mid=(l+h)/2;
	        if(mid-1>=0 && a[mid-1]>a[mid]) return mid;
	        else if(mid+1<n && a[mid+1]<a[mid]) return mid+1;
	        else if(a[l]<=a[mid]){
	            mini=min(mini,a[l]);
	            l=mid+1;
	        }
	       else{
	           mini=min(mini,a[mid]);
	           h=mid-1;
	       }
	    }
	    
	    return mini;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends