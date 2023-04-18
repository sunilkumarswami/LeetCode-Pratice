//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
        int ind1=-1,ind2;
        for(int i=n-1;i>0;i--){
            if(a[i-1]<a[i]){
                ind1=i-1;
                break;
            }
        }
        if(ind1==-1){
            reverse(a.begin(),a.end());
            return a;
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]>a[ind1]){
                ind2=i;
                break;
            }
        }
        swap(a[ind1],a[ind2]);
        reverse(a.begin()+ind1+1,a.end());
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