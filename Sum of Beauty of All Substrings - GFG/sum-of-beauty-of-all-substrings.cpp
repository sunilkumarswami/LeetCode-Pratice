//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int maxi=1,mini=n;
                for(auto it:mp){
                    if(maxi<it.second)
                        maxi=it.second;
                    if(mini>it.second)
                        mini=it.second;
                }
                ans+=maxi-mini;
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends