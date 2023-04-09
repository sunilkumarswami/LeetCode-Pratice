//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& a) {
        // Code here
        int n=a.size(),m=a[0].size();
        vector<vector<int> > b=a;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]==0){
                    if(i-1>=0){
                        b[i][j]+=a[i-1][j];
                        b[i-1][j]=0;
                    }
                    if(j-1>=0){
                        b[i][j]+=a[i][j-1];
                        b[i][j-1]=0;
                    }
                    if(i+1<n){
                        b[i][j]+=a[i+1][j];
                        b[i+1][j]=0;
                    }
                    if(j+1<m){
                        b[i][j]+=a[i][j+1];
                        b[i][j+1]=0;
                    }
                }
            }
        }
        a=b;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends