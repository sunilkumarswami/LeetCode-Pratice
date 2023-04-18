//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll> ans;
        if(n==1){
            ans.push_back(1);
            return ans;
        }
        ll mod=1000000007;
        ans.push_back(1);
        ans.push_back(1);
        if(n==2){
            return ans;
        }
        for(int i=3;i<=n;i++){
            vector<ll> v;
            v.push_back(1);
            for(int j=0;j<ans.size()-1;j++){
                v.push_back((ans[j]%mod+ans[j+1]%mod)%mod);
            }
            v.push_back(1);
            ans=v;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends