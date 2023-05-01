//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        int n=s.size();
        int last=n-1;
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]=='.' || i==0){
                int j;
                if(i==0) j=0;
                else j=i+1;
                // string st="";
                // for(;j<=last;j++){
                //   st+=s[j]; 
                // }
                ans+=s.substr(j,last-j+1);
                if(i!=0){
                    ans+=".";
                }
                last=i-1;
                // ans+=st;
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends