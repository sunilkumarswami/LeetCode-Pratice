//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int x,int y,string s,vector<vector<int>> &a, vector<string> &ans){
        int n=a.size();
        // cout<<s<<endl;
        
            if(x==n-1 && y==n-1) {
                ans.push_back(s);
            return;
        }
        a[x][y]=0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n && a[nx][ny]==1){
                // a[nx][ny]=0;
                if(i==0) s+='R';
                if(i==1) s+='L';
                if(i==2) s+='D';
                if(i==3) s+='U';
                solve(nx,ny,s,a,ans);
                s.pop_back();
                // a[nx][ny]=1;
            }
        }
        a[x][y]=1;
    }
    vector<string> findPath(vector<vector<int>> &a, int n) {
        // Your code goes here
        if(a[0][0]==0 || a[n-1][n-1]==0) return {"-1"};
        vector<string> ans;
       string s="";
       solve(0,0,s,a,ans);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends