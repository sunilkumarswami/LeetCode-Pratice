//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(m>n) return -1;
        long long l=1e9,h=0;
        for(int i=0;i<n;i++){
            l=min(l,(long long)a[i]);
            h+=a[i];
        }
        while(l<=h){
            long long mid=(l+h)/2;
            int sum=0,cnt=0,i;
            for(i=0;i<n;i++){
                if(a[i]>mid){
                    break;
                }
                else if(sum+a[i]==mid){
                    sum=0;
                    cnt++;
                }
                else if((sum+a[i])>mid){
                    sum=a[i];
                    cnt++;
                }
                else sum+=a[i];
            }
            if(sum!=0) cnt++;
            if(i !=n || cnt>m) l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends