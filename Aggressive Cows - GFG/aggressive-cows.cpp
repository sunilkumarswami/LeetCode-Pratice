//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &a) {
    
        // Write your code here
        sort(a.begin(),a.end());
        int l=0,h=1e9;
        while(l<=h){
            int mid=(l+h)/2;
            int c=k-1,total=a[0]+mid;
            for(int i=1;i<n;i++){
                if(total<=a[i]){
                    c--;
                    total=a[i]+mid;
                }
                if(c<=0) break;
            }
            if(c<=0){
                l=mid+1;
            }
            else h=mid-1;
        }
        return h;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends