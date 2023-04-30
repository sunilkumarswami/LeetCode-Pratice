class Solution {
public:
    int search(vector<int>& a, int key) {
        int l=0,h=a.size()-1;
        int n=h+1;
        while(l<=h){
            int mid=(l+h)/2;
            if(a[mid]==key) return mid;
            else if(a[0]<=a[mid]){
                if(a[mid]>key && key>=a[0])
                    h=mid-1;
                else 
                    l=mid+1;
            }
            else{
                if(a[mid]<key && key<= a[n-1])
                    l=mid+1;
                else 
                    h=mid-1;
            }
        }
        return -1;
    }
};