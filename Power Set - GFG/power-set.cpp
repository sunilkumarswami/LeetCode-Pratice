//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(int i,string s,string str,vector<string> &ans,int n){
	        if(i==n){
	            if(s.size()>0)
	            ans.push_back(s);
	            return;
	        }
	        solve(i+1,s,str,ans,n);
	        s+=str[i];
	        solve(i+1,s,str,ans,n);
	    }
		vector<string> AllPossibleStrings(string str){
		    string s="";
		    int n=str.size();
		    vector<string> ans;
		    solve(0,s,str,ans,n);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends