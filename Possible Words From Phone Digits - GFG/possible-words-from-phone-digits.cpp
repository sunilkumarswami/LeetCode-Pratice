//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int ind,int dig[],unordered_map<int,string> &mp,string &str,vector<string> &ans,int n){
        if(ind==n){
            ans.push_back(str);
            return;
        }
        string s= mp[dig[ind]];
        
        for(int i=0;i<s.size();i++){
            str.push_back(s[i]);
            solve(ind+1,dig,mp,str,ans,n);
            str.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int n)
    {
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string str="";
        vector<string>  ans;
        if(n==0) return ans;
        solve(0,a,mp,str,ans,n);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends