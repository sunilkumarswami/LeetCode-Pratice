class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int X) {
        int n=a.size(),m=a[0].size();
        int l=0,h=n*m-1;
	    while(l<=h){
	        int mid=(l+h)/2;
	        int k=mid/m;
	       // k%=n;
	        if(a[k][mid%m]==X) return 1;
	        else if(a[k][mid%m]>X) h=mid-1;
	        else l=mid+1;
	    }
	    return 0;
    }
};