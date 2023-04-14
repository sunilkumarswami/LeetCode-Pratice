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
        sort(a,a+n);
        int cnt=1,maxi=1;
        for(int i=1;i<n;i++){
            if((a[i]-a[i-1])==1) cnt++;
            else if((a[i]-a[i-1])==0);
            else{
                maxi=max(cnt,maxi);
                cnt=1;
            }
        }
        maxi=max(cnt,maxi);
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