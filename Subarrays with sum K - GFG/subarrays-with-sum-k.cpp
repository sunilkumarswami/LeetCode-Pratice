//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int a[], int n, int k)
    {
        int cnt=0;
        long long sum=0;
        map<long long,int> mp;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==k) cnt++;
            if(mp.find(sum-k)!=mp.end())
                cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends