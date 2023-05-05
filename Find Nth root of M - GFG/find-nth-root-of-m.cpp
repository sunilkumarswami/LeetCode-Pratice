//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long l=1,h=m;
	    while(l<=h){
	        long long mid=(l+h)/2,val=1,i;
	       for(i=1;i<=n;i++){
	           val*=mid;
	           if(val>m){
	               h=mid-1;
	               break;
	           }
	       }
	       if(i>n){
	           if(val==m) return mid;
	           else if(val>m) h=mid-1;
	           else l=mid+1;
	       }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends