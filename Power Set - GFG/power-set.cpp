//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
		vector<string> AllPossibleStrings(string str){
		    string s="";
		    int n=str.size();
		    vector<string> ans;
		    for(int num=0;num<pow(2,n);num++){
		        string s="";
		        for(int i=0;i<n;i++){
		            if(1<<i& num){
		                s+=str[i];
		            }
		        }
		        if(s.size()>0)
		        ans.push_back(s);
		    }
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