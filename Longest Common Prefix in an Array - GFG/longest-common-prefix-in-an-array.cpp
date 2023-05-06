//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string a[], int n)
    {
        // your code here
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int m=a[i].size();
            mini=min(mini,m);
        }
        
            for(int j=0;j<mini;j++){
                for(int i=1;i<n;i++){
                if(a[i][j]!=a[0][j]){
                    if(j==0) return "-1";
                    return a[0].substr(0,j);
                }
            }
        }
       return a[0].substr(0,mini); 
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends