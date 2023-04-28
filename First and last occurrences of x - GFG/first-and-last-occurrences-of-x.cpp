//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int a[], int n , int x )
{
    // code here
    vector<int> v;
    int l=0,r=n-1,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x){
            ans=mid;
            r=mid-1;
        }
        else if(a[mid]>x){
            r=mid-1;
        }
        else 
            l=mid+1;
    }

    v.push_back(ans);
    ans=-1;
    l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x){
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]<x){
            l=mid+1;
        }
        else 
            r=mid-1;
    }
    v.push_back(ans);
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends