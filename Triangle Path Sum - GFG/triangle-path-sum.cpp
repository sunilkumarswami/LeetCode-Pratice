//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& tri) {
        
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            vector<int> temp(tri[i].size(),-1);
            dp.push_back(temp);
        }
        
        for(int j=0;j<tri[n-1].size();j++){
            dp[n-1][j]=tri[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<tri[i].size();j++){
                dp[i][j] = tri[i][j] +min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends