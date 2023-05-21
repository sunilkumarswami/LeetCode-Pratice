//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(int N, vector<vector<int>> &a) {
        sort(a.begin(),a.end());
        int last=a[0][1],diff(a[0][1]-a[0][0]),ans=0;
        for(int i=1;i<a.size();i++){
            if(a[i][0]<last){
                last=min(last,a[i][1]);
                ans++;
            }
            else{
                last=a[i][1];
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
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends