//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
        unordered_set<int> st(a,a+n);
        int cnt=1,maxi=1;
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                x++;
                while(st.find(x)!=st.end()){
                    x++;
                    cnt++;
                }
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends