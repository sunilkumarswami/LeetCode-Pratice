//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int a[], int n){
        // Your code here
        if(n==1) return 0;
        int i=0,ans=0;
        while(i<n){
            if(a[i]==0) return -1;
            if(a[i]>=(n-1-i)) return ans+1;
            int m=a[i],maxi=INT_MIN,ind=i+1;
            for(int j=i+1;j<=min(i+m,n-1);j++){
                if(maxi<=(a[j]+j)){
                    ind=j;
                    maxi=a[j]+j;
                }
            }
            i=ind;
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends