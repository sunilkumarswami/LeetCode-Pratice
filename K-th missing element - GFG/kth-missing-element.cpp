//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    
        // if(a[n-1]==n) return -1;
        if((a[n-1]-(a[0]+n-1))<k) return -1;
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int missing=a[mid]-(a[0]+mid);
            if(missing<k) l=mid+1;
            else h=mid-1;
        }
        if(h==-1) return h=0;
        return a[h]+k-(a[h]-(a[0]+h));
}