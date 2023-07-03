//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int ind,int sum,int k,vector<int> &ds,vector<vector<int>> &ans){
        if(sum==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(ds.size()>k) return;
        for(int i=ind;i<9;i++){
            if(i+1<=sum){
                ds.push_back(i+1);
                solve(i+1,sum-i-1,k,ds,ans);
                ds.pop_back();
            }
            else break;
        }
    }
  
    vector<vector<int>> combinationSum(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,n,k,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends