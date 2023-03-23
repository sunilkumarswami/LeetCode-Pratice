//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    void func(int i,long long last1,long long last2,vector<long long> &ans){
        if(i==0) return;
        
        ans.push_back(last1+last2);
        func(--i,last2,last1+last2,ans);
    }
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> ans;
        
        ans.push_back(1);
        if(n==1) return ans;
        ans.push_back(1);
        func(n-2,1,1,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends