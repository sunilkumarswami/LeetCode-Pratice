//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int a[], int b[], int n, int m, int k)
    {
        if(m<n)
        return kthElement(b,a,m,n,k);
        int l=0,h=n;
        while(l<=h){
            int cut1=(l+h)/2;
            int cut2=k-cut1;
            if(cut1>k){
                h=cut1-1;
            }
            else if(cut2>m){
                l=cut1+1;
            }
            else{
                int l1=INT_MIN,l2=INT_MIN,m1=INT_MAX,m2=INT_MAX;
                if(cut1-1>=0 && cut1-1<n) l1=a[cut1-1];
                if(cut1>=0 && cut1<n) m1=a[cut1];
                if(cut2-1>=0 && cut2-1<m) l2=b[cut2-1];
                if(cut2>=0 && cut2<m) m2=b[cut2];
                if(l1<=m2 && l2<=m1) return max(l1,l2);
                else if(l1>m2) h=cut1-1;
                else l=cut1+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends