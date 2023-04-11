//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int s=0,rt=0,r=n-1,c=m-1,t=0;
        while(1){
            for(int j=s;j<=c;j++){
                k--;
                if(k==0) {
                    return a[s][j];
                }
            }
            
            for(int i=s+1;i<=r;i++){
                k--;
                if(k==0) return a[i][c];
            }
            
            for(int j=c-1;j>=s;j--){
                k--;
                if(k==0) {
                    return a[r][j];
                }
            }
            for(int i=r-1;i>s;i--){
                k--;
                if(k==0) return a[i][s];
            }
            s++,c--,r--,t++;
        }
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends