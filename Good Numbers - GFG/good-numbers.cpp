//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int i,int R,int d,vector<int> &ans){
        if(i>R || i>99999) return;
        int n=i,sum=0;
        if(d!=0 && n%10==0) n/=10;
        while(n){
            int rem=n%10;
            if(rem==d || rem<=sum) break;
            sum+=rem;
            n/=10;
        }
        if(n==0) ans.push_back(i);
        solve(i+1,R,d,ans);
    }
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> ans;
        solve(L,R,D,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends