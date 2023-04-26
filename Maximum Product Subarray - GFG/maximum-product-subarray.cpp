//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> a, int n) {
	    long long maxi=a[0],mini=a[0],ans=a[0];
	    for(int i=1;i<n;i++){
	        long long x=(long long)a[i];
	        if(a[i]<0)
	            swap(maxi,mini);
	        
	            maxi=max((long long)a[i],maxi*a[i]);
	            mini=min((long long)a[i],mini*a[i]);
	        
	        ans=max(ans,maxi);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends