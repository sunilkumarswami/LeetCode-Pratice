//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& a) {
         // Code here
         vector<vector<int>> ans;
         
         sort(a.begin(),a.end());
         int last=a[0][1],n=a.size();
         ans.push_back(a[0]);
         for(int i=0;i<n;i++){
             if(last<a[i][0]){
                 ans.push_back(a[i]);
                 last=a[i][1];
             }
             else{
                 last=max(a[i][1],ans.back()[1]);
                 ans.back()[1]=last;
             }
         }
         
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends