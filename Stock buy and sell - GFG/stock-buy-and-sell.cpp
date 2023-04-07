//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int a[], int n) {
    // code here
    long long profit=0,first=0;
    bool flag=false;
    for(int i=1;i<n;i++){
        if((a[i]-a[i-1])>=0){
            profit+=(a[i]-a[i-1]);
        }
        else{
            if(profit>0){
                cout<<"("<<first<<" "<<i-1<<") ";
                profit=0;
                flag=true;
            }
            first=i;
        }
    }
    if(profit>0){
                cout<<"("<<first<<" "<<n-1<<") ";
                flag=true;
            }
            if(!flag) cout<<"No Profit";
        cout<<endl;
}