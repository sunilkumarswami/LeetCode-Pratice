class Solution {
public:
    bool isSafe(int x,int y,vector<string> &a){
        int n=a.size();
        int dx[]={0,0,1,-1,1,1,-1,-1};
        int dy[]={1,-1,0,0,1,-1,1,-1};
        for(int k=0;k<8;k++){
            int i=x+dx[k],j=y+dy[k];
            while(i>=0 && j>=0 && i<n && j<n){
                if(a[i][j]=='Q') return false;
                i=i+dx[k];
                j=j+dy[k];
            }
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