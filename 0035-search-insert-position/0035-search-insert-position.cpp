class Solution {
public:
    int searchInsert(vector<int>& a, int k) {
        int N=a.size();
        int l=0,h=N-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(a[mid]==k){
                return mid;
            }
            else if(a[mid]<k)
                l=mid+1;
            else
                h=mid-1;
        }
        return l;
    }
};