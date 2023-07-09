//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int x,int y,vector<string> &a){
        int n=a.size();
        int i=x,j=y;
        while(i>=0){
            if(a[i][j]=='Q') return false;
            i--;
        }
        i=x,j=y;
        while(i>=0 && j>=0){
            if(a[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=x,j=y;
        while(i>=0 && j<n){
            if(a[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(int i,vector<string> &a, vector<vector<int>> &ans){
        int n=a.size();
        if(i==n){
            vector<int> v;
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    if(a[x][y]=='Q') v.push_back(y+1);
                }
            }
            ans.push_back(v);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(isSafe(i,j,a)){
                a[i][j]='Q';
                solve(i+1,a,ans);
                a[i][j]='.';
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<string> a;
        string s(n,'.');
        for(int i=0;i<n;i++) a.push_back(s);
        
            solve(0,a,ans);
         
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends