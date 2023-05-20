class Solution {
public:
    bool canJump(vector<int>& a) {
        int n=a.size();
        if(n==1) return true;
        int i=0;
        while(i<n){
            if(a[i]==0) return false;
            if(a[i]>=(n-1-i)) return true;
            int m=a[i],maxi=INT_MIN,ind=i+1;
            for(int j=i+1;j<=min(i+m,n-1);j++){
                if(maxi<=(a[j]+j)){
                    ind=j;
                    maxi=a[j]+j;
                }
            }
            i=ind;
        }
        return true;
    }
};