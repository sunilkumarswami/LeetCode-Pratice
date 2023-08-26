//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& a, int n) {
        vector<vector<int>> dp(n,vector<int>(4,0));
    int val=-1;
    vector<int> last(n,0);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=j)
            dp[0][i]=max(dp[0][i],a[0][j]);
        }
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            int ans=0;
            for(int k=0;k<3;k++){
                if(k!=j){
                    ans=max(ans,a[i][k]+dp[i-1][k]);
                }
            }
            dp[i][j]=ans;
        }
    }
    
    for(int j=0;j<3;j++)
    val=max(val,dp[n-1][j]);
    
    return val;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends