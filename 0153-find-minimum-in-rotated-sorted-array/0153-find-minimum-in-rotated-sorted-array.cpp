class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int l=0,h=n-1,mini=INT_MAX;
        while(l<=h){
            int mid=(l+h)/2;
            if(a[l]<=a[mid]){
                mini=min(mini,a[l]);
                l=mid+1;
            }
            else{
                mini=min(mini,a[mid]);
                h=mid-1;
            }
        }
        return mini;
    }
};