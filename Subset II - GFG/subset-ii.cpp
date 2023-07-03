//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  void solve(int ind,vector<int> &v,vector<int> &a,vector<vector<int>> &ans){
        ans.push_back(v);
        if(ind==a.size()) {
            return;}
        
        for(int i=ind;i<a.size();i++){
            if(i>ind && a[i]==a[i-1]) continue;
            v.push_back(a[i]);
            solve(i+1,v,a,ans);
            v.pop_back();
        }
    }
    
    
  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,v,a,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends