//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > a, int n, int m) {
	    // code here
	    int ans=-1,mini=INT_MAX;
	    for(int i=0;i<n;i++){
	        int l=0,h=m-1;
	        int val=INT_MAX;
	        while(l<=h){
	            int mid=(l+h)/2;
	            if(a[i][mid]==1){
	                val=mid;
	                h=mid-1;
	            }
	            else{
	                l=mid+1;
	            }
	            if(val<mini){
	                mini=val;
	                ans=i;
	            }
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends