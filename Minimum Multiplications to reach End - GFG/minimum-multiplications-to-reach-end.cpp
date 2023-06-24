//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
typedef long long ll;
#define mod (ll)1e5
class Solution {
  public:
    int minimumMultiplications(vector<int>& a, int start, int end) {
        int n=a.size();
        vector<int> dist(mod,1e9);
        queue<pair<int,int>> pq;
        pq.push({start,0});
        
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            long long val=it.first,level=it.second;
            
            for(int i=0;i<n;i++){
                long long temp=val*a[i];
                temp=temp%mod;
                if(temp==end) return level+1;
                if(dist[temp]>level+1){
                    dist[temp]=level+1;
                    pq.push({temp,level+1});
                }
                
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends