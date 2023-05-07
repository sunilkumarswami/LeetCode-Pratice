//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int k, vector<int> &a){
      if((long long)m*k>a.size()) return -1;
        long long l=1,h=10e9;
        while(l<=h){
            long long mid=l+(h-l)/2;
            int cnt=0,total=0;
            for(int i=0;i<a.size();i++){
                if(a[i]<=mid){
                    cnt++;
                    if(cnt>=k){
                        total++;
                        cnt=0;
                    }
                }
                else cnt=0;
            }
            if(total>=m) h=mid-1;
            else l=mid+1;
        }
        return l;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends