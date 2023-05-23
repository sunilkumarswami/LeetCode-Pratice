//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &a) {
        int five=0,ten=0;
        for(int i=0;i<n;i++){
            if(a[i]==5) five++;
            else if(a[i]==10 && five>0){
                ten++;
                five--;
            }
            else if(a[i]==20 && ten>0 && five>0){
                ten--;
                five--;
            }
            else if(a[i]==20 && five>2){
                five-=3;
            }
            else return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends