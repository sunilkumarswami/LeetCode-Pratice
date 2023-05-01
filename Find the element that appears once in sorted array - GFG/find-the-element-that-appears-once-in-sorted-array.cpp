//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int a[], int n)
    {
        //code here.
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid-1>=0 && a[mid-1]==a[mid]){
                if(mid%2==0)
                    h=mid-1;
                else 
                    l=mid+1;
            }
            else if(mid+1<n && a[mid+1]==a[mid]){
                if(mid%2!=0)
                    h=mid-1;
                else 
                    l=mid+1; 
            }
            else return a[mid];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends