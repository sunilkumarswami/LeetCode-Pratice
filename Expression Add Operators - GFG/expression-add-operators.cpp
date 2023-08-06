//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i,string st,string s,long long pre,long long total,int tar,vector<string> &ans){
        
        int n=s.size();
        if(i==s.size()){
            // cout<<st<<" "<<total<<endl;
            if(total==tar){
                ans.push_back(st);
            }
                
            return;
        }
        
        for(int j=i;j<n;j++){
            string str=s.substr(i,j-i+1);
            long long cur=stoll(str);
            if(s[i]=='0' && j==i+1) break;
            if(i==0){
                solve(j+1,str,s,cur,cur,tar,ans);
            }
            else{
                solve(j+1,st+"+"+str,s,cur,total+cur,tar,ans);
                solve(j+1,st+"-"+str,s,-cur,total-cur,tar,ans);
                solve(j+1,st+"*"+str,s,pre*cur,total-pre+pre*cur,tar,ans);
            }
        }
    }
    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        string st="";
        solve(0,st,s,0,0,target,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends