//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int a[], int n, int x) {
    // code here
    sort(a,a+n);
    int ceils=-1,floors=-1,l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==x){
            return {x,x};
        }
        else if(a[mid]<x){
            floors=a[mid];
            l=mid+1;
        }
        else{
            ceils=a[mid];
            r=mid-1;
        }
    }
    return {floors,ceils};
}