//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &a, vector<int> &ni) {
        vector<vector<int>> ans;
        // int n=a.size();
        if(n==0) {
            ans.push_back(ni);
            return ans;
        }
        
        bool flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                if(a[i][1]<ni[0]){
                    ans.push_back(a[i]);
                }
                else{
                    flag=false;
                    if(ni[1]>=a[i][0])
                    ans.push_back({min(ni[0],a[i][0]),max(ni[1],a[i][1])});
                    else{
                        ans.push_back(ni);
                        ans.push_back(a[i]);
                    }
                }
            }
            else{
                if(a[i][0]<=ans.back()[1]){
                    ans.back()[1]=max(ans.back()[1],a[i][1]);
                }
                else ans.push_back(a[i]);
            }
        }
        if(a[n-1][1]<ni[0]) ans.push_back(ni);
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
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends