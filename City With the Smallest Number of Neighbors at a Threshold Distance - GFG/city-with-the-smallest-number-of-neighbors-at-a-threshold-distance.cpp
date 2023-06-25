//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     vector<vector<int>> a(n,vector<int> (n,1e9));
        
        for(auto it:edges){
            a[it[0]][it[1]]=it[2];
            a[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++) a[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
                }
            }
        }
        int mini=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[i][j]<=distanceThreshold) cnt++;
            }
            if(mini>=cnt){
                mini=cnt;
                ans=i;
            }
        }
        return ans;
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends