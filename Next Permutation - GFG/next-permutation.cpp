//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
        int i1=-1,i2;
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                i1=i;
                break;
            }
        }
        if(i1==-1){
            reverse(a.begin(),a.end());
            return a;
        }
        for(int i=n-1;i>=0;i--){
            if(a[i1]<a[i]){
                i2=i;
                break;
            }
        }
        swap(a[i1],a[i2]);
        reverse(a.begin()+i1+1,a.end());
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends