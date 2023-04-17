//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int a[], int n) {
	    vector<int> b(n,0);
	    int cntPos=0,cntNeg=0;
	    for(int k=0;k<n;k++){
	        if(a[k]>=0) 
	            cntPos++;
	        else 
	            cntNeg++;
	    }
	    int m=min(cntPos,cntNeg);
	    int i=0,j=0;
	    for(int k=0;k<n;k++){
	        if(a[k]>=0){
	            if(i<m){
	                b[2*i]=a[k];
	            }
	            if(i==m) 
	                i=2*i;
	            if(i>=m)
	            b[i]=a[k];
	            i++;
	        }
	        else{
	            if(j<m){
	                b[2*j+1]=a[k];
	            }
	            if(j==m) 
	                j=2*j;
	            if(j>=m)
	            b[j]=a[k];
	            j++;
	        }
	    }
	    for(int i=0;i<n;i++)
	        a[i]=b[i];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends