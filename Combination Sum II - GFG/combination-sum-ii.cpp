//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
void solve(int ind,int sum,vector<int> &v,vector<int> &a,vector<vector<int>> &ans){
        
            if(sum==0) {
                ans.push_back(v);
            }
        for(int i=ind;i<a.size();i++){
            if(i>ind && a[i-1]==a[i]) continue;
            
                if(a[i]>sum) break;
                v.push_back(a[i]);
                solve(i+1,sum-a[i],v,a,ans);
                v.pop_back();
        }    
    }

class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int> &a, int target) {
        // Write your code here
        vector<int> v;
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        solve(0,target,v,a,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends