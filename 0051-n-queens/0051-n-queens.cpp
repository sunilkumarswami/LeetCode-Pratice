class Solution {
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
    void solve(int i,vector<string> &a, vector<vector<string>> &ans){
        int n=a.size();
        if(i==n){
            ans.push_back(a);
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> a;
        string s(n,'.');
        for(int i=0;i<n;i++) a.push_back(s);
        
            solve(0,a,ans);
         
        return ans;
    }
};