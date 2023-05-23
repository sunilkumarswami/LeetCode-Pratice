//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        while(N>=2000) {
            ans.push_back(2000);
            N-=2000;
        }
        while(N>=500) {
            ans.push_back(500);
            N-=500;
        }
        while(N>=200) {
            ans.push_back(200);
            N-=200;
        }
        while(N>=100) {
            ans.push_back(100);
            N-=100;
        }
        while(N>=50) {
            ans.push_back(50);
            N-=50;
        }
        while(N>=20) {
            ans.push_back(20);
            N-=20;
        }
        while(N>=10) {
            ans.push_back(10);
            N-=10;
        }
        while(N>=5) {
            ans.push_back(5);
            N-=5;
        }
        while(N>=2) {
            ans.push_back(2);
            N-=2;
        }
        while(N>=1) {
            ans.push_back(1);
            N-=1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends