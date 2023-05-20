//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int> &a,pair<int,int> &b){
         return a.second<b.second;
        return a.first<b.first;
        // return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int ans=1;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        // for(auto x:v){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        int last=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>last){
                ans++;
                last=v[i].second;
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
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends