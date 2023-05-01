class Solution {
public:
    bool search(vector<int>& a, int key) {
        int n=a.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(a[mid]==key) return true;
            else if(a[l]==a[mid] && a[mid]==a[h]){
                l++,h--;
            }
            else if(a[l]<=a[mid]){
                if(a[mid]>key && key>=a[l])
                    h=mid-1;
                else 
                    l=mid+1;
            }
            else{
                if(a[mid]<key && key<= a[h])
                    l=mid+1;
                else 
                    h=mid-1;
            }
        }
        return false;
    }
};