//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(int i,string s, set<string> &st,vector<int> &dp){
        if(i>=s.size())
        {
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        string s1="";
        for(int j=i;j<s.size();j++){
            s1+=s[j];
            if(st.find(s1)!=st.end()){
                if(solve(j+1,s,st,dp)==1) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }

    int wordBreak(string s, vector<string> &wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,st,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends