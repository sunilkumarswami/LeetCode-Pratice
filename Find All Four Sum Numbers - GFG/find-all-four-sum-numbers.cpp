//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int X) {
        // Your code goes here
        vector<vector<int>> ans;
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n;){
            for(int j=i+1;j<n;){
                int k=j+1,l=n-1;
                while(k<l){
                    int total=a[i]+a[j]+a[k]+a[l];
                    if(total==X){
                        vector<int> v;
                        v.push_back(a[i]);
                        v.push_back(a[j]);
                        v.push_back(a[k]);
                        v.push_back(a[l]);
                        sort(v.begin(),v.end());
                        ans.push_back(v);
                        while(k+1<n && a[k]==a[k+1]) k++;
                        while(l-1>=0 && a[l-1]==a[l]) l--;
                        k++,l--;
                    }
                    else if(total>X) l--;
                    else k++;
                }
                while(j+1<n && a[j]==a[j+1]) j++;
                j++;
            }
            while(i+1<n && a[i]==a[i+1]) i++;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends